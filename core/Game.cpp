#include "Game.h"

Game::Game() {}

Game::~Game() {}

#include "PlayerHuman.h"
#include "PlayerAI.h"
#include "PlayerRemote.h"

void Game::run() {
	initialization();
	char winner = loop();
	ending(winner);
}

void Game::initialization() {
	//Interface - pobierz ustawienia gry (typy graczy, rozmiar planszy)
	//inicjalizacja pierwszego gracza
	switch (player1Type) {
	case playerType::HUMAN:
		player1 = std::make_unique<PlayerHuman>(BOARDSIZE);
		break;
	case playerType::AI:
		player1 = std::make_unique<PlayerAI>(BOARDSIZE);
		break;
	case playerType::REMOTE:
		player1 = std::make_unique<PlayerRemote>(BOARDSIZE);
		break;
	default:
		;//Interface - zg³oœ b³¹d
	}
	//inicjalizacja drugiego gracza
	switch (player2Type) {
	case playerType::HUMAN:
		player2 = std::make_unique<PlayerHuman>(BOARDSIZE);
		break;
	case playerType::AI:
		player2 = std::make_unique<PlayerAI>(BOARDSIZE);
		break;
	case playerType::REMOTE:
		player2 = std::make_unique<PlayerRemote>(BOARDSIZE);
		break;
	default:
		;//Interface - zg³oœ b³¹d
	}
	//Wymiana wskaŸników na plansze
	player1->setOtherBoard(player2->getMyBoard());
	player2->setOtherBoard(player1->getMyBoard());
}

char Game::loop() {
	char winner = 0;
	//todo: losowy wybór rozpoczynaj¹cego gracza
	while (winner == 0) {
		//interface - ruch gracza 1
		player1->move();
		if (winner != 0)
			break;
		//interface - ruch gracza 2
		player2->move();
	}
	return winner;
}

void Game::ending(char winner) {

}