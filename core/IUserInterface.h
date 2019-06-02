#pragma once
#include "Point.hpp"
class PlannerLocal; //PlannerLocal

class IUserInterface {
public:
	//przekazuje planer planszy do utworzenia planszy, wstrzymuje program do zakoñczenia tworzenia
	virtual void makeBoard(PlannerLocal* planner) = 0;
	//zwraca wspó³rzêdne strza³u
	virtual Point getShotCoords() = 0;
	//poinformuj interfejs o zmianie na planszy 'id'; waitForRespond wstrzymuje dzia³anie programu do otrzymania odpowiedzi (interfejs odczyta³ zmianê)
	virtual void boardChanged(int id, bool waitForRespond = false) = 0;
	//przekazuje informacje o zakoñczeniu gry
	virtual void gameEnded(char winner) = 0;
	//wirtualny destruktor
	//virtual ~IUserInterface() = 0;
};
