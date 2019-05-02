#pragma once
#include "Board.h" //Board
#include <memory> //std::unique_ptr

class Player {
protected:
	enum ShotResult { SUNK, HIT, MISS }; //rezultat strza³u
	const int BOARDSIZE; //rozmiar planszy
	Board& myBoard; //w³asna plansza
	Board& otherBoard; //plansza przeciwnika
public:
	//konstruktor
	Player(int _BOARDSIZE, Board& _myBoard, Board& _otherBoard);
	//destruktor
	virtual ~Player();
	//gracz wykonuje swój ruch
	virtual void move();
};