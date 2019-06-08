#include "Game.h"

//konstruktor
Game::Game(IUserInterface& _mainInterface) : mainInterface(_mainInterface) {}

//destruktor
Game::~Game() {}

//uruchom gr�
void Game::run() {
	initialization();
	//char winner = loop(); //tymczasowo wy��czone
	//ending(winner); //tymczasowo wy��czone
	player1Type = PlayerType::AI; //temp
	player2Type = PlayerType::AI; //temp
}

#include "CreatorBoard.h"

//cz�� gry - inicjalizacja
void Game::initialization() {
	//Interface - pobierz ustawienia gry (typy graczy, rozmiar planszy)
	//Tworzenie plansz graczy
	board1 = CreatorBoard(BOARDSIZE, mainInterface).makeBoard(player1Type);
	board2 = CreatorBoard(BOARDSIZE, mainInterface).makeBoard(player2Type);
	//Sprawdzanie poprawno�ci utworzenia plansz i rejestracja plansz w interfejsie
	if (board1 == nullptr)
		mainInterface.error("An error has occured during initialization board for player 1", true);
	else
		mainInterface.registerBoard(1, board1->getId());
	if (board2 == nullptr)
		mainInterface.error("An error has occured during initialization board for player 2", true);
	else
		mainInterface.registerBoard(2, board1->getId());
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
		//interface - ruch gracza 1
		player1->move();
		//interface - ruch gracza 2
		player2->move();
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
	return winner;
}

//cz�� gry - zako�czenie
void Game::ending(char winner) {

}

//#include "UserDllInterface.h"
#include "PlayerHuman.h"
#include "PlayerAI.h"
#include "PlayerRemote.h"
//inicjalizuje graczy
void Game::initializePlayers() {
	switch (player1Type) {
	case PlayerType::HUMAN:
		player1 = std::make_unique<PlayerHuman>(mainInterface, BOARDSIZE, *board1, *board2);
		break;
	case PlayerType::AI:
		player1 = std::make_unique<PlayerAI>(BOARDSIZE, *board1, *board2);
		break;
	case PlayerType::REMOTE:
		player1 = std::make_unique<PlayerRemote>(BOARDSIZE, *board1, *board2);
		break;
	default:
		player1 = nullptr;
	}
	//inicjalizacja drugiego gracza
	switch (player2Type) {
	case PlayerType::HUMAN:
		player2 = std::make_unique<PlayerHuman>(mainInterface, BOARDSIZE, *board1, *board2);
		break;
	case PlayerType::AI:
		player2 = std::make_unique<PlayerAI>(BOARDSIZE, *board1, *board2);
		break;
	case PlayerType::REMOTE:
		player2 = std::make_unique<PlayerRemote>(BOARDSIZE, *board1, *board2);
		break;
	default:
		player2 = nullptr;
	}
}