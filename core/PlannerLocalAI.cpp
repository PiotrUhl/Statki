#include "PlannerLocalAI.h"

PlannerLocalAI::PlannerLocalAI(int _BOARDSIZE) : PlannerLocal(_BOARDSIZE) {
}

//tworzy z u�yciem interfejsu i zwraca utworzon� plansz�
std::unique_ptr<BoardLocal> PlannerLocalAI::makeBoard() {
	return nullptr;
}