#pragma once
#include "Board.h" //Board
#include <memory> //std::unique_ptr

class Player {
protected:
	enum ShotResult { SUNK, HIT, MISS }; //rezultat strza³u
	const int BOARD_SIZE; //rozmiar planszy
	std::unique_ptr<Board> myBoard; //w³asna plansza
	Board* otherBoard; //plansza przeciwnika
public:
	//konstruktor
	Player(int _BOARD_SIZE);
	//destruktor
	virtual ~Player();
	//gracz wykonuje swój ruch
	virtual void move();
};