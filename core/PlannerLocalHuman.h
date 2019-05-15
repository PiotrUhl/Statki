#pragma once
#include "PlannerLocal.h"

class PlannerLocalHuman : public PlannerLocal {
public:
	PlannerLocalHuman(int _BOARDSIZE); //konstruktor
	//tworzy z u¿yciem interfejsu i zwraca utworzon¹ planszê
	std::unique_ptr<BoardLocal> makeBoard();
};