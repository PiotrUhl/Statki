#pragma once
#include "Player.h"
#include "Point.hpp"
#include <list> //std::list

class PlayerAI : public Player {
private:
	boost::multi_array<bool, 2> shootableMap; //todo: przerobiæ na bitset
	int shootableCount;
	bool finishMode; //tryb wykañczania postrzelonego statku
	Point finishStart; //punkt z którego zaczêto tryb wykañczania
	std::list<Point> finishList; //lista punktów w których mo¿e znajdowaæ siê pozosta³a czêœæ postrzelonego statku
public:
	//konstruktor
	PlayerAI(Board& _myBoard, Board& _otherBoard);
	//destruktor
	~PlayerAI();
	//gracz wykonuje swój ruch
	void move() override;
private:
	//przechodzi w tryb wykañczania z pocz¹tkiem w punkcie point
	void setFinishMode(Point point);
	//losuje punkt w którym mo¿e znajdowaæ siê statek
	Point chooseSquare();
	//losuje punkt spoœród punktów w których mo¿e znajdowaæ siê reszta postrzelonego statku
	Point chooseFinish();
	//uzupe³nia tablicê shootableMap o wyniki strza³u w point
	void updateShootableMap(Point point, ShotResult result);
	//losuje losow¹ liczbê naturaln¹ z zakresu <1, b>
	int randomNumber(int b);
};
