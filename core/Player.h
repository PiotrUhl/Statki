#pragma once
#include "Board.h" //Board
#include <memory> //std::unique_ptr

class Player {
protected:
	enum ShotResult { SUNK, HIT, MISS }; //rezultat strza�u
	const int BOARD_SIZE; //rozmiar planszy
	std::unique_ptr<Board> myBoard; //w�asna plansza
	Board* otherBoard; //plansza przeciwnika
public:
	//konstruktor
	Player(int _BOARD_SIZE);
	//destruktor
	virtual ~Player();
	//zwraca wska�nik na swoj� plansz�
	Board* getMyBoard();
	//ustawia wska�nik na plansz� przeciwnika
	void setOtherBoard(Board* _otherBoard);
	//gracz wykonuje sw�j ruch
	virtual void move();
};