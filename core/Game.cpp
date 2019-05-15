#include "Game.h"

//konstruktor
Game::Game() {}

//destruktor
Game::~Game() {}

//uruchom grê
void Game::run() {
	initialization();
	char winner = loop();
	ending(winner);
}

#include "CreatorBoard.h"

//czêœæ gry - inicjalizacja
void Game::initialization() {
	//Interface - pobierz ustawienia gry (typy graczy, rozmiar planszy)
	//Tworzenie plansz graczy
	board1 = CreatorBoard(BOARDSIZE).makeBoard(player1Type);
	board2 = CreatorBoard(BOARDSIZE).makeBoard(player2Type);
	//Sprawdzanie poprawnoœci utworzenia plansz
	if (board1 == nullptr)
		;//interface - zg³oœ b³¹d
	if (board2 == nullptr)
		;//interface - zg³oœ b³¹d
	//Inicjalizacja graczy
	initializePlayers();
	//Sprawdzanie poprawnoœci inicjalizacji graczy
	if (player1 == nullptr)
		;//interface - zg³oœ b³¹d
	if (player2 == nullptr)
		;//interface - zg³oœ b³¹d
}

/*#include "BoardLocal.h"
#include "BoardRemote.h"
#include "PlannerLocalHuman.h"
#include "PlannerLocalAI.h"
//tworzy i zwraca planszê dla gracza o typie "plType" //deleted
std::unique_ptr<Board> Game::makeBoard(Game::playerType plType) {
	switch (plType) {
	case playerType::HUMAN:
		return PlannerLocalHuman(BOARDSIZE).makeBoard();
		break;
	case playerType::AI:
		return PlannerLocalAI(BOARDSIZE).makeBoard();
		break;
	case playerType::REMOTE:
		return std::make_unique<BoardRemote>(BOARDSIZE);
		break;
	default:
		return nullptr;
	}
}*/

//czêœæ gry - g³ówna pêtla
char Game::loop() {
	char winner = 0;
	//todo: losowy wybór rozpoczynaj¹cego gracza
	while (winner == 0) {
		//interface - ruch gracza 1
		player1->move();
		//interface - ruch gracza 2
		player2->move();
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
	return winner;
}

//czêœæ gry - zakoñczenie
void Game::ending(char winner) {

}

#include "PlayerHuman.h"
#include "PlayerAI.h"
#include "PlayerRemote.h"
//inicjalizuje graczy
void Game::initializePlayers() {
	switch (player1Type) {
	case playerType::HUMAN:
		player1 = std::make_unique<PlayerHuman>(BOARDSIZE, *board1, *board2);
		break;
	case playerType::AI:
		player1 = std::make_unique<PlayerAI>(BOARDSIZE, *board1, *board2);
		break;
	case playerType::REMOTE:
		player1 = std::make_unique<PlayerRemote>(BOARDSIZE, *board1, *board2);
		break;
	default:
		player1 = nullptr;
	}
	//inicjalizacja drugiego gracza
	switch (player2Type) {
	case playerType::HUMAN:
		player2 = std::make_unique<PlayerHuman>(BOARDSIZE, *board1, *board2);
		break;
	case playerType::AI:
		player2 = std::make_unique<PlayerAI>(BOARDSIZE, *board1, *board2);
		break;
	case playerType::REMOTE:
		player2 = std::make_unique<PlayerRemote>(BOARDSIZE, *board1, *board2);
		break;
	default:
		player2 = nullptr;
	}
}