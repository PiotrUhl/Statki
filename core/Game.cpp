#include "Game.h"

//konstruktor
Game::Game(InitData _init, IUserInterface& _mainInterface) : player1Type(_init.player1type), player2Type(_init.player2type), mainInterface(_mainInterface), currentPlayer(0) {}

//destruktor
Game::~Game() {}

//uruchom grê
void Game::run() {
	initialization();
	char winner = loop();
	ending(winner);
}

int Game::getCurrentPlayer() const {
	return currentPlayer;
}

#include "CreatorBoard.h"
//czêœæ gry - inicjalizacja
void Game::initialization() {
	//Tworzenie plansz graczy
	board1 = CreatorBoard(mainInterface).makeBoard(player1Type);
	board2 = CreatorBoard(mainInterface).makeBoard(player2Type);
	//Sprawdzanie poprawnoœci utworzenia plansz i rejestracja plansz w interfejsie
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
	//Sprawdzanie poprawnoœci inicjalizacji graczy
	if (player1 == nullptr)
		mainInterface.error("An error has occured during initialization player 1", true);
	if (player2 == nullptr)
		mainInterface.error("An error has occured during initialization player 2", true);
}

//czêœæ gry - g³ówna pêtla
char Game::loop() {
	char winner = 0;
	//todo: losowy wybór rozpoczynaj¹cego gracza
	while (winner == 0) {
		currentPlayer = 1;
		player1->move();
		mainInterface.sendShotInfo(player1->getOtherBoardId(), player1->getLastShotPoint(), player1->getLastShotResult());
		currentPlayer = 2;
		player2->move();
		mainInterface.sendShotInfo(player2->getOtherBoardId(), player2->getLastShotPoint(), player2->getLastShotResult());
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