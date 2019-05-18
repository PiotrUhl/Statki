#pragma once
#include "PlannerLocal.h"
#include <bitset>

class PlannerLocalAI : private PlannerLocal {
private:
	std::vector<std::vector<std::bitset<8>>> placeable;
public:
	PlannerLocalAI(int _BOARDSIZE);
	//tworzy za pomoc¹ algorytmu i zwraca planszê
	BoardLocal makeBoard();
};

