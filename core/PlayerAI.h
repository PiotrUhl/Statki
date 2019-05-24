#pragma once
#include "Player.h"
#include <vector>
#include <list>

class PlayerAI : public Player {
private:
	struct Point {
		Point(int _x, int _y) { x = _x; y = _y; }
		int x;
		int y;
	};
	std::vector<std::vector<bool>> shootableMap;
	int shootableCount;
	bool finishMode; //tryb wyka�czania postrzelonego statku
	std::list<Point> finishList; //lista punkt�w w kt�rych mo�e znajdowa� si� pozosta�a cz�� postrzelonego statku
public:
	//konstruktor
	PlayerAI(int _BOARDSIZE, Board& _myBoard, Board& _otherBoard);
	//destruktor
	~PlayerAI();
	//gracz wykonuje sw�j ruch
	void move() override;
private:
	void setFinishMode(Point point);
	//losuje punkt w kt�rym mo�e znajdowa� si� statek
	Point chooseSquare();
	//uzupe�nia tablic� shootableMap o wyniki strza�u w point
	void updateShootableMap(Point point);
	//losuje losow� liczb� naturaln� z zakresu <1, b>
	int randomNumber(int b);
};
