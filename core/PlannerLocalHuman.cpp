#include "PlannerLocalHuman.h"

PlannerLocalHuman::PlannerLocalHuman(int _BOARDSIZE) : PlannerLocal(_BOARDSIZE) {
}

PlannerLocalHuman::~PlannerLocalHuman() {
}

//tworzy z u�yciem interfejsu i zwraca utworzon� plansz�
std::unique_ptr<BoardLocal> PlannerLocalHuman::makeBoard() {
	return nullptr;
}