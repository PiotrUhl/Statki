#pragma once
//#include "UserInterface.h"
#include "Player.h" //Player
#include "Board.h" //Board
#include <memory> //std::unique_ptr

class Game {
public:
	enum class playerType { NONE, HUMAN, AI, REMOTE };
private:
	int BOARDSIZE; //rozmiar planszy
	playerType player1Type; //typ gracza 1
	playerType player2Type; //typ gracza 2
	std::unique_ptr<Board> board1; //plansza gracza nr 1
	std::unique_ptr<Board> board2; //plansza gracza nr 2
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
	//tworzy i zwraca planszê dla gracza o typie "plType"
	//std::unique_ptr<Board> makeBoard(playerType plType); //deleted
	//inicjalizuje graczy; zwraca sukces/pora¿kê
	void initializePlayers();
};