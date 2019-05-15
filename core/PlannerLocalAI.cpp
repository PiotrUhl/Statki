#include "PlannerLocalAI.h"

PlannerLocalAI::PlannerLocalAI(int _BOARDSIZE) : PlannerLocal(_BOARDSIZE) {
}

//tworzy z u¿yciem interfejsu i zwraca utworzon¹ planszê
std::unique_ptr<BoardLocal> PlannerLocalAI::makeBoard() {
	return nullptr;
}