#pragma once
#include "PlannerLocal.h"

class PlannerLocalHuman : public PlannerLocal {
public:
	PlannerLocalHuman(int _BOARDSIZE); //konstruktor
	~PlannerLocalHuman(); //destruktor
	//tworzy z u�yciem interfejsu i zwraca utworzon� plansz�
	std::unique_ptr<BoardLocal> makeBoard();
};