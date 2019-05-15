#pragma once
#include "PlannerLocal.h"

class PlannerLocalAI : public PlannerLocal {
public:
	PlannerLocalAI(int _BOARDSIZE); //konstruktor
	//tworzy z u¿yciem algorytmu i zwraca utworzon¹ planszê
	std::unique_ptr<BoardLocal> makeBoard();
};