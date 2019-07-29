#pragma once
#include "structs.hpp" //ShipInfo, Point
#include <list> //std::list

class PlannerLocal; //PlannerLocal

class IUserInterface {
public:
	//wypisuje na ekranie b³¹d "error'; "critical" przerywa dzia³anie programu
	virtual void error(const char* error, bool critical = true) = 0;
	//przekazuje planer planszy do utworzenia planszy
	virtual void makeBoard(PlannerLocal*) = 0;
	//rejestruje id planszy w interfejsie
	virtual void registerBoard(int, int) = 0;
	//zwraca wspó³rzêdne strza³u
	virtual Point getShotCoords() = 0;
	//poinformuj interfejs o zmianie na planszy
	virtual void boardChanged(int, std::list<ShipInfo>, boost::multi_array<ShotResult, 2>) = 0;
	//przekazuje informacje o zakoñczeniu gry
	virtual void gameEnded(char winner) = 0;
	//zg³asza do interfejsu wyniki strza³u
	virtual void sendShotInfo(int, Point, ShotResult) = 0;
};
