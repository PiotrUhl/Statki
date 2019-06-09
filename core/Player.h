#pragma once
#include "Board.h" //Board
#include "structs.hpp" //ShotResult
#include "Point.hpp"
#include <memory> //std::unique_ptr

class Player {
protected:
	const int BOARDSIZE; //rozmiar planszy
	Board& myBoard; //w�asna plansza
	Board& otherBoard; //plansza przeciwnika
	Point lastShotPoint; //miejsce ostatniego strza�u
	ShotResult lastShotResult; //rezultat ostatniego strza�u
public:
	//konstruktor
	Player(int _BOARDSIZE, Board& _myBoard, Board& _otherBoard);
	//destruktor
	virtual ~Player();
	//gracz wykonuje sw�j ruch
	virtual void move() = 0;
	//zwraca miejsce ostatniego strza�u
	Point getLastShotPoint();
	//zwraca rezultat ostatniego strza�u
	ShotResult getLastShotResult();
	//zwraca ID swojej planszy
	int getMyBoardId();
	//zwraca ID planszy przeciwnika
	int getOtherBoardId();
};