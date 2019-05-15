#pragma once
#include "PlannerLocal.h"

class PlannerLocalAI : public PlannerLocal {
public:
	PlannerLocalAI(int _BOARDSIZE); //konstruktor
	//tworzy z u�yciem algorytmu i zwraca utworzon� plansz�
	std::unique_ptr<BoardLocal> makeBoard();
};