#pragma once
#include "Point.hpp"
class PlannerLocal; //PlannerLocal

class IUserInterface {
public:
	//przekazuje planer planszy do utworzenia planszy, wstrzymuje program do zako�czenia tworzenia
	virtual void makeBoard(PlannerLocal* planner) = 0;
	//zwraca wsp�rz�dne strza�u
	virtual Point getShotCoords() = 0;
	//poinformuj interfejs o zmianie na planszy 'id'; waitForRespond wstrzymuje dzia�anie programu do otrzymania odpowiedzi (interfejs odczyta� zmian�)
	virtual void boardChanged(int id, bool waitForRespond = false) = 0;
	//przekazuje informacje o zako�czeniu gry
	virtual void gameEnded(char winner) = 0;
	//wirtualny destruktor
	//virtual ~IUserInterface() = 0;
};
