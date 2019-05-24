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
	bool finishMode; //tryb wykañczania postrzelonego statku
	std::list<Point> finishList; //lista punktów w których mo¿e znajdowaæ siê pozosta³a czêœæ postrzelonego statku
public:
	//konstruktor
	PlayerAI(int _BOARDSIZE, Board& _myBoard, Board& _otherBoard);
	//destruktor
	~PlayerAI();
	//gracz wykonuje swój ruch
	void move() override;
private:
	void setFinishMode(Point point);
	//losuje punkt w którym mo¿e znajdowaæ siê statek
	Point chooseSquare();
	//uzupe³nia tablicê shootableMap o wyniki strza³u w point
	void updateShootableMap(Point point);
	//losuje losow¹ liczbê naturaln¹ z zakresu <1, b>
	int randomNumber(int b);
};
