#pragma once
#include "Board.h" //Board
#include "structs.hpp" //ShotResult
#include <memory> //std::unique_ptr

class Player {
protected:
	const int BOARDSIZE; //rozmiar planszy
	Board& myBoard; //w�asna plansza
	Board& otherBoard; //plansza przeciwnika
public:
	//konstruktor
	Player(int _BOARDSIZE, Board& _myBoard, Board& _otherBoard);
	//destruktor
	virtual ~Player();
	//gracz wykonuje sw�j ruch
	virtual void move();
};