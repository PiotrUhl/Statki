#pragma once
#include "UserInterface.h"
#include "Player.h"
#include <memory> //std::unique_ptr

class Player;

class Game {
private:
	int BOARDSIZE; //rozmiar planszy
	enum class playerType { NONE, HUMAN, AI, REMOTE };
	playerType player1Type; //typ gracza 1
	playerType player2Type; //typ gracza 2
	std::unique_ptr<Player> player1; //gracz nr 1
	std::unique_ptr<Player> player2; //gracz nr 2
public:
	//konstruktor
	Game();
	//destruktor
	~Game();
	//uruchom grê
	void run();
private:
	//czêœæ gry - inicjalizacja
	void initialization();
	//czêœæ gry - g³ówna pêtla
	char loop();
	//czêœæ gry - zakoñczenie
	void ending(char winner);
};