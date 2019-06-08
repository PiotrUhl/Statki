#pragma once
#include "Point.hpp"
#include "Board.h"
#include <list>
class PlannerLocal; //PlannerLocal

class IUserInterface {
public:
	//przekazuje planer planszy do utworzenia planszy, wstrzymuje program do zako�czenia tworzenia
	virtual void makeBoard(PlannerLocal*) = 0;
	//rejestruje id planszy w interfejsie
	virtual void registerBoard(int, int) = 0;
	//zwraca wsp�rz�dne strza�u
	virtual Point getShotCoords() = 0;
	//poinformuj interfejs o zmianie na planszy
	virtual void boardChanged(std::list<Board::ShipInfo>, std::vector<std::vector<ShotResult>>) = 0;
	//przekazuje informacje o zako�czeniu gry
	virtual void gameEnded(char winner) = 0;
};
