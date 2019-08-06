#include "Game.h"

//konstruktor
Game::Game(InitData _init, IUserInterface& _mainInterface) : player1Type(_init.player1type), player2Type(_init.player2type), mainInterface(_mainInterface), currentPlayer(0), lastShotBoard(0) {}

//destruktor
Game::~Game() {}

//uruchom grê
void Game::run() {
	initialization();
	char winner = loop();
	ending(winner);
}

//zwraca currentPlayer
int Game::getCurrentPlayer() const {
	return currentPlayer;
}

//zwraca lastShotBoard
int Game::getLastShotBoard() const {
	return lastShotBoard;
}

//zwraca miejsce ostatniego strza³u w planszê 'boardId'; (BOARDSIZE, BOARDSIZE) w razie b³êdu
Point Game::getLastShotPoint(int boardId) const {
	const Board* board = findBoardById(boardId);
	if (board == nullptr)
		return Point{ BOARDSIZE, BOARDSIZE };
	else
		return board->getLastShotPoint();
}

//zwraca wynik ostatniego strza³u w planszê 'boardId'
ShotResult Game::getLastShotResult(int boardId) const {
	const Board* board = findBoardById(boardId);
	if (board == nullptr)
		return ShotResult::NONE;
	else
		return board->getLastShotResult();
}

//zwraca typ gracza 'playerId' b¹dŸ NONE w przypadku niew³aœciwego gracza
PlayerType Game::getPlayerType(int playerId) const {
	switch (playerId) {
	case 1:
		return player1Type;
	case 2:
		return player2Type;
	default:
		return PlayerType::NONE; //error!
	}
}

//zwraca obraz planszy 'boardId'
boost::multi_array<unsigned char, 2> Game::getBoardImage(int boardId) const {
	const Board* board = findBoardById(boardId);
	if (board == nullptr)
		return boost::multi_array<unsigned char, 2>(boost::extents[0][0]);
	else
		return board->getImage();
}

//zwraca obraz punktu 'point' na planszy 'boardId'
unsigned char Game::getSquareImage(int boardId, Point point) const {
	const Board* board = findBoardById(boardId);
	if (board == nullptr)
		return 255;
	else
		return board->getSquareImage(point);
}

//zwraca mapê strza³ów planszy 'boardId'
boost::multi_array<ShotResult, 2> Game::getShotMap(int boardId) const {
	const Board* board = findBoardById(boardId);
	if (board == nullptr)
		return boost::multi_array<ShotResult, 2>(boost::extents[0][0]);
	else
		return board->getShotMap();
}
//zwraca informacjê o strzale w pole 'point' na planszy 'boardId'
ShotResult Game::getSquareShot(int boardId, Point point) const {
	const Board* board = findBoardById(boardId);
	if (board == nullptr)
		return ShotResult::NONE;
	else
		return board->getSquareShot(point);
}

//zwraca informacje o statku le¿¹cym na polu 'point' na planszy 'boardId'
ShipInfo Game::getSquareShip(int boardId, Point point) const {
	const Board* board = findBoardById(boardId);
	if (board == nullptr)
		return ShipInfo{ 0, 0, 0, 0, 0 };
	else
		return board->getSquareShip(point);
}

//zwraca listê informacji o wszystkich statkach na planszy 'boardId'
std::list<ShipInfo> Game::getShipList(int boardId) const {
	const Board* board = findBoardById(boardId);
	if (board == nullptr)
		return std::list<ShipInfo>();
	else
		return board->getShipList();
}

//zwraca liczbê statków na planszy 'boardId'
int Game::getShipCount(int boardId) const {
	const Board* board = findBoardById(boardId);
	if (board == nullptr)
		return -1;
	else
		return board->getShipCount();
}

#include "CreatorBoard.h"
//czêœæ gry - inicjalizacja
void Game::initialization() {
	//Tworzenie plansz graczy
	board1 = CreatorBoard(mainInterface).makeBoard(player1Type);
	board2 = CreatorBoard(mainInterface).makeBoard(player2Type);
	//Sprawdzanie poprawnoœci utworzenia plansz
	if (board1 == nullptr)
		mainInterface.msg("An error has occured during initialization board for player 1", MsgType::ERROR, true);
	else 
		mainInterface.event_boardCreated(1);
	if (board2 == nullptr)
		mainInterface.msg("An error has occured during initialization board for player 2", MsgType::ERROR, true);
	else
		mainInterface.event_boardCreated(2);
	//Inicjalizacja graczy
	initializePlayers();
	//Sprawdzanie poprawnoœci inicjalizacji graczy
	if (player1 == nullptr)
		mainInterface.msg("An error has occured during initialization player 1", MsgType::ERROR, true);
	if (player2 == nullptr)
		mainInterface.msg("An error has occured during initialization player 2", MsgType::ERROR, true);
}

//czêœæ gry - g³ówna pêtla
char Game::loop() {
	char winner = 0;
	//toadd: losowy wybór rozpoczynaj¹cego gracza
	while (winner == 0) {
		currentPlayer = 1;
		player1->move();
		lastShotBoard = 2;
		mainInterface.event_playerMoved(1);
		//mainInterface.sendShotInfo(2, player1->getLastShotPoint(), player1->getLastShotResult());
		currentPlayer = 2;
		player2->move();
		lastShotBoard = 1;
		mainInterface.event_playerMoved(2);
		//mainInterface.sendShotInfo(1, player2->getLastShotPoint(), player2->getLastShotResult());
		if (board2->getUnsunkShips() == 0) { //je¿eli wszystkie statki na planszy 2 s¹ zatopione
			if (board1->getUnsunkShips() == 0) { //oraz wszystkie statki na planszy 1 s¹ zatopione
				winner = 3; //remis
			}
			else {
				winner = 1; //wygrywa gracz 1
			}
		}
		else if (board1->getUnsunkShips() == 0) { //je¿eli wszystkie statki na planszy 1 s¹ zatopione
			winner = 2; //wygrywa gracz 2
		}
	}
	currentPlayer = 0;
	return winner;
}

//czêœæ gry - zakoñczenie
void Game::ending(char winner) {
	if (winner == 1)
		mainInterface.msg("Wygrana", MsgType::INFO, false);
	else if (winner == 2)
		mainInterface.msg("Przegrana", MsgType::INFO, false);
	else
		mainInterface.msg("Remis", MsgType::INFO, false);
}

//#include "UserDllInterface.h"
#include "PlayerHuman.h"
#include "PlayerAI.h"
#include "PlayerRemote.h"
//inicjalizuje graczy
void Game::initializePlayers() {
	switch (player1Type) {
	case PlayerType::HUMAN:
		player1 = std::make_unique<PlayerHuman>(mainInterface, *board1, *board2);
		break;
	case PlayerType::AI:
		player1 = std::make_unique<PlayerAI>(*board1, *board2);
		break;
#ifdef NETMODULE
	case PlayerType::REMOTE:
		player1 = std::make_unique<PlayerRemote>(*board1, *board2);
		break;
#endif
	default:
		player1 = nullptr;
	}
	//inicjalizacja drugiego gracza
	switch (player2Type) {
	case PlayerType::HUMAN:
		player2 = std::make_unique<PlayerHuman>(mainInterface, *board2, *board1);
		break;
	case PlayerType::AI:
		player2 = std::make_unique<PlayerAI>(*board2, *board1);
		break;
#ifdef NETMODULE
	case PlayerType::REMOTE:
		player2 = std::make_unique<PlayerRemote>(*board2, *board1);
		break;
#endif
	default:
		player2 = nullptr;
	}
}

//zwraca referencje na planszê o podanym id
Board* Game::findBoardById(int boardId) {
	return const_cast<Board*>(const_cast<const Game*>(this)->findBoardById(boardId));
}

//zwraca referencje na planszê o podanym id
const Board* Game::findBoardById(int boardId) const {
	switch (boardId) {
	case 1:
		return board1.get();
	case 2:
		return board2.get();
	default:
		return nullptr;
	}
}
