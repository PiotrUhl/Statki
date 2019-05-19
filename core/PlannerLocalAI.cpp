#include "PlannerLocalAI.h"
#include <ctime>

PlannerLocalAI::PlannerLocalAI(int _BOARDSIZE) : PlannerLocal(_BOARDSIZE), placeableMap(BOARDSIZE, std::vector<std::bitset<8>>(BOARDSIZE)) {
	int allSquares = BOARDSIZE * BOARDSIZE;
	for (int i = 0; i < 8; i++)
		placeableSquares[i] = allSquares;
	srand(time(NULL));
}

void PlannerLocalAI::initializeplaceableMap() {
	for (auto k : placeableMap) { //ustawianie ca³oœci na 1
		for (auto l : k) {
			l.set();
		}
	}
	for (int i = 0; i < BOARDSIZE; i++) { //ostatnia kolumna
		placeableMap[BOARDSIZE - 1][i][static_cast<int>(ShipPlacement::H4)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::H4)]--;
		placeableMap[BOARDSIZE - 1][i][static_cast<int>(ShipPlacement::H3)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::H3)]--;
		placeableMap[BOARDSIZE - 1][i][static_cast<int>(ShipPlacement::H2)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::H2)]--;
	}
	for (int i = 0; i < BOARDSIZE; i++) { //przedostatnia kolumna
		placeableMap[BOARDSIZE - 2][i][static_cast<int>(ShipPlacement::H4)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::H4)]--;
		placeableMap[BOARDSIZE - 2][i][static_cast<int>(ShipPlacement::H3)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::H3)]--;
	}
	for (int i = 0; i < BOARDSIZE; i++) { //przedprzedostatnia kolumna
		placeableMap[BOARDSIZE - 3][i][static_cast<int>(ShipPlacement::H4)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::H3)]--;
	}
	for (int i = 0; i < BOARDSIZE; i++) { //ostatni wiersz
		placeableMap[i][BOARDSIZE - 1][static_cast<int>(ShipPlacement::V4)] = false; 
		placeableSquares[static_cast<int>(ShipPlacement::V4)]--;
		placeableMap[i][BOARDSIZE - 1][static_cast<int>(ShipPlacement::V3)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::V3)]--;
		placeableMap[i][BOARDSIZE - 1][static_cast<int>(ShipPlacement::V2)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::V2)]--;
	}
	for (int i = 0; i < BOARDSIZE; i++) { //przedostatni wiersz
		placeableMap[i][BOARDSIZE - 2][static_cast<int>(ShipPlacement::V4)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::V4)]--;
		placeableMap[i][BOARDSIZE - 2][static_cast<int>(ShipPlacement::V3)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::V3)]--;
	}
	for (int i = 0; i < BOARDSIZE; i++) { //przedprzedostatni wiersz
		placeableMap[i][BOARDSIZE - 3][static_cast<int>(ShipPlacement::V4)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::V4)]--;
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
	initializeplaceableMap();
	board.clear();
}