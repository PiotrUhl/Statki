#pragma once
#include "Player.h"
#include "Point.hpp"
#include <list> //std::list

class PlayerAI : public Player {
private:
	boost::multi_array<bool, 2> shootableMap; //todo: przerobi� na bitset
	int shootableCount;
	bool finishMode; //tryb wyka�czania postrzelonego statku
	Point finishStart; //punkt z kt�rego zacz�to tryb wyka�czania
	std::list<Point> finishList; //lista punkt�w w kt�rych mo�e znajdowa� si� pozosta�a cz�� postrzelonego statku
public:
	//konstruktor
	PlayerAI(Board& _myBoard, Board& _otherBoard);
	//destruktor
	~PlayerAI();
	//gracz wykonuje sw�j ruch
	void move() override;
private:
	//przechodzi w tryb wyka�czania z pocz�tkiem w punkcie point
	void setFinishMode(Point point);
	//losuje punkt w kt�rym mo�e znajdowa� si� statek
	Point chooseSquare();
	//losuje punkt spo�r�d punkt�w w kt�rych mo�e znajdowa� si� reszta postrzelonego statku
	Point chooseFinish();
	//uzupe�nia tablic� shootableMap o wyniki strza�u w point
	void updateShootableMap(Point point, ShotResult result);
	//losuje losow� liczb� naturaln� z zakresu <1, b>
	int randomNumber(int b);
};
