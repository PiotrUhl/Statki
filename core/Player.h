#pragma once
#include "Board.h" //Board
#include <memory> //std::shared_ptr

class Player {
private:
	const int BOARD_SIZE; //rozmiar planszy
	Board myBoard; //w�asna plansza
	Board* otherBoard; //plansza przeciwnika
public:
	//konstruktor
	Player(int _BOARD_SIZE);
	//destruktor
	virtual ~Player();
	//gracz wykonuje sw�j ruch
	virtual void move();
};