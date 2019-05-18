#include "PlannerLocalAI.h"
#include <ctime>

//placeable:
//0: 1H
//1: 1V
//2: 2H
//3: 2V
//4: 3H
//5: 3V
//6: 4H
//7: 4V

PlannerLocalAI::PlannerLocalAI(int _BOARDSIZE) : PlannerLocal(_BOARDSIZE), placeable(BOARDSIZE, std::vector<std::bitset<8>>(BOARDSIZE)) {
	srand(time(NULL));
}

void PlannerLocalAI::initializeplaceable() {
	for (auto k : placeable) { //ustawianie ca³oœci na 1
		for (auto l : k) {
			l.set();
		}
	}
	for (int i = 0; i < BOARDSIZE; i++) { //ostatnia kolumna
		placeable[BOARDSIZE - 1][i][6] = false; //4H
		placeable[BOARDSIZE - 1][i][4] = false; //3H
		placeable[BOARDSIZE - 1][i][2] = false; //2H
	}
	for (int i = 0; i < BOARDSIZE; i++) { //przedostatnia kolumna
		placeable[BOARDSIZE - 2][i][6] = false; //4H
		placeable[BOARDSIZE - 2][i][4] = false; //3H
	}
	for (int i = 0; i < BOARDSIZE; i++) { //przedprzedostatnia kolumna
		placeable[BOARDSIZE - 3][i][6] = false; //4H
	}
	for (int i = 0; i < BOARDSIZE; i++) { //ostatni wiersz
		placeable[i][BOARDSIZE - 1][7] = false; //4V
		placeable[i][BOARDSIZE - 1][5] = false; //3V
		placeable[i][BOARDSIZE - 1][3] = false; //2V
	}
	for (int i = 0; i < BOARDSIZE; i++) { //przedostatni wiersz
		placeable[i][BOARDSIZE - 2][7] = false; //4V
		placeable[i][BOARDSIZE - 2][5] = false; //3V
	}
	for (int i = 0; i < BOARDSIZE; i++) { //przedprzedostatni wiersz
		placeable[i][BOARDSIZE - 3][7] = false; //4V
	}
}

//tworzy za pomoc¹ algorytmu i zwraca planszê
BoardLocal PlannerLocalAI::makeBoard() {
	bool repeat = false;
	do {
		resetBoard();
		repeat = !place4();
		repeat = !place3();
		repeat = !place3();
		repeat = !place2();
		repeat = !place2();
		repeat = !place2();
		repeat = !place1();
		repeat = !place1();
		repeat = !place1();
		repeat = !place1();
	} while (repeat == true);
	return getBoard();
}

bool PlannerLocalAI::place4() {
	return true;
}
bool PlannerLocalAI::place3() {
	return true;
}
bool PlannerLocalAI::place2() {
	return true;
}
bool PlannerLocalAI::place1() {
	return true;
}
void PlannerLocalAI::resetBoard() {
	initializeplaceable();
}