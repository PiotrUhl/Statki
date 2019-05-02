#pragma once
#include "PlannerLocal.h"

class PlannerLocalAI : public PlannerLocal {
public:
	PlannerLocalAI(int _BOARDSIZE); //konstruktor
	~PlannerLocalAI(); //destruktor
	//tworzy z u�yciem interfejsu i zwraca utworzon� plansz�
	std::unique_ptr<BoardLocal> makeBoard();
};

