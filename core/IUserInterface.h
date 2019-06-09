#pragma once
#include "Point.hpp" //Point
#include "structs.hpp" //ShipInfo
#include <list> //std::list

class PlannerLocal; //PlannerLocal

class IUserInterface {
public:
	//wypisuje na ekranie b��d "error'; "critical" przerywa dzia�anie programu
	virtual void error(const char* error, bool critical = true) = 0;
	//przekazuje planer planszy do utworzenia planszy
	virtual void makeBoard(PlannerLocal*) = 0;
	//rejestruje id planszy w interfejsie
	virtual void registerBoard(int, int) = 0;
	//zwraca wsp�rz�dne strza�u
	virtual Point getShotCoords() = 0;
	//poinformuj interfejs o zmianie na planszy
	virtual void boardChanged(int, std::list<ShipInfo>, std::vector<std::vector<ShotResult>>) = 0;
	//przekazuje informacje o zako�czeniu gry
	virtual void gameEnded(char winner) = 0;
	//zg�asza do interfejsu wyniki strza�u
	virtual void sendShotInfo(Point, ShotResult) = 0;
};
