#pragma once
#include "PlannerLocal.h"

class PlannerLocalAI : public PlannerLocal {
public:
	PlannerLocalAI(int _BOARDSIZE); //konstruktor
	~PlannerLocalAI(); //destruktor
	//tworzy z u¿yciem interfejsu i zwraca utworzon¹ planszê
	std::unique_ptr<BoardLocal> makeBoard();
};

