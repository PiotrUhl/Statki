#include "Game.h"

//konstruktor
Game::Game(InitData _init, IUserInterface& _mainInterface) : player1Type(_init.player1type), player2Type(_init.player2type), mainInterface(_mainInterface), currentPlayer(0), lastShotBoard(0) {}

//destruktor
Game::~Game() {}

//uruchom gr�
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

//zwraca miejsce ostatniego strza�u w plansz� 'boardId'; (BOARDSIZE, BOARDSIZE) w razie b��du
Point Game::getLastShotPoint(int boardId) const {
	switch (boardId) {
	case 1:
		return board1->getLastShotPoint();
	case 2:
		return board2->getLastShotPoint();
	default:
		return Point{ BOARDSIZE, BOARDSIZE };
	}
}

//zwraca wynik ostatniego strza�u w plansz� 'boardId'
ShotResult Game::getLastShotResult(int boardId) const {
	switch (boardId) {
	case 1:
		return board1->getLastShotResult();
	case 2:
		return board2->getLastShotResult();
	default:
		return ShotResult::NONE;
	}
}

//zwraca typ gracza 'playerId' b�d� NONE w przypadku niew�a�ciwego gracza
PlayerType Game::getPlayerType(int playerId) const {
	switch (playerId) {
	case 1:
		return player1Type;
	case 2:
		return player2Type;
	default:
		return PlayerType::NONE;
	}
}

//zwraca obraz planszy 'boardId'
boost::multi_array<char, 2> Game::getBoardImage(int boardId) const {
	switch (boardId) {
	case 1:
		return board1->getImage();
	case 2:
		return board2->getImage();
	default:
		return boost::multi_array<char, 2>(boost::extents[0][0]);
	}
}

//zwraca obraz punktu 'point' na planszy 'boardId'
unsigned char Game::getSquareImage(int boardId, Point point) const {
	switch (boardId) {
	case 1:
		return board1->getSquareImage(point);
	case 2:
		return board2->getSquareImage(point);
	default:
		return 255;
	}
}

//zwraca map� strza��w planszy 'boardId'
boost::multi_array<ShotResult, 2> Game::getShotMap(int boardId) const {
	switch (boardId) {
	case 1:
		return board1->getShotMap();
	case 2:
		return board2->getShotMap();
	default:
		return boost::multi_array<ShotResult, 2>(boost::extents[0][0]);
	}
}
//zwraca informacj� o strzale w pole 'point' na planszy 'boardId'
ShotResult Game::getSquareShot(int boardId, Point point) const {
	switch (boardId) {
	case 1:
		return board1->getSquareShot(point);
	case 2:
		return board2->getSquareShot(point);
	default:
		return ShotResult::NONE; //error!
	}
}

#include "CreatorBoard.h"
//cz�� gry - inicjalizacja
void Game::initialization() {
	//Tworzenie plansz graczy
	board1 = CreatorBoard(mainInterface).makeBoard(player1Type);
	board2 = CreatorBoard(mainInterface).makeBoard(player2Type);
	//Sprawdzanie poprawno�ci utworzenia plansz i rejestracja plansz w interfejsie
	if (board1 == nullptr)
		mainInterface.error("An error has occured during initialization board for player 1", true);
	else
		mainInterface.registerBoard(1, board1->getId());
	if (board2 == nullptr)
		mainInterface.error("An error has occured during initialization board for player 2", true);
	else
		mainInterface.registerBoard(2, board2->getId());
	//Inicjalizacja graczy
	initializePlayers();
	//Sprawdzanie poprawno�ci inicjalizacji graczy
	if (player1 == nullptr)
		mainInterface.error("An error has occured during initialization player 1", true);
	if (player2 == nullptr)
		mainInterface.error("An error has occured during initialization player 2", true);
}

//cz�� gry - g��wna p�tla
char Game::loop() {
	char winner = 0;
	//todo: losowy wyb�r rozpoczynaj�cego gracza
	while (winner == 0) {
		currentPlayer = 1;
		player1->move();
		lastShotBoard = 2;
		mainInterface.sendShotInfo(player1->getOtherBoardId(), player1->getLastShotPoint(), player1->getLastShotResult());
		currentPlayer = 2;
		player2->move();
		lastShotBoard = 1;
		mainInterface.sendShotInfo(player2->getOtherBoardId(), player2->getLastShotPoint(), player2->getLastShotResult());
		if (board2->getUnsunkShips() == 0) { //je�eli wszystkie statki na planszy 2 s� zatopione
			if (board1->getUnsunkShips() == 0) { //oraz wszystkie statki na planszy 1 s� zatopione
				winner = 3; //remis
			}
			else {
				winner = 1; //wygrywa gracz 1
			}
		}
		else if (board1->getUnsunkShips() == 0) { //je�eli wszystkie statki na planszy 1 s� zatopione
			winner = 2; //wygrywa gracz 2
		}
	}
	currentPlayer = 0;
	return winner;
}

//cz�� gry - zako�czenie
void Game::ending(char winner) {
	if (winner == 1)
		mainInterface.error("Wygrana", false);
	else if (winner == 2)
		mainInterface.error("Przegrana", false);
	else
		mainInterface.error("Remis", false);
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