#include "PlannerLocalAI.h"
#include <ctime>
#include <cstdlib>

PlannerLocalAI::PlannerLocalAI(BoardLocal& _board) : PlannerLocal(_board), placeableMap(boost::extents[BOARDSIZE][BOARDSIZE]) {
	srand((unsigned int)time(NULL));
	initializeplaceableMap();
}

void PlannerLocalAI::initializeplaceableMap() {
	for (int i = 0; i < 8; i++)
		placeableSquares[i] = BOARDSIZE * BOARDSIZE;
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			placeableMap[i][j].set();
		}
	}
	for (int i = 0; i < BOARDSIZE; i++) { //ostatnia kolumna
		placeableMap[BOARDSIZE - 1][i][static_cast<int>(ShipPlacement::V5)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::V5)]--;
		placeableMap[BOARDSIZE - 1][i][static_cast<int>(ShipPlacement::V4)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::V4)]--;
		placeableMap[BOARDSIZE - 1][i][static_cast<int>(ShipPlacement::V3)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::V3)]--;
		placeableMap[BOARDSIZE - 1][i][static_cast<int>(ShipPlacement::V2)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::V2)]--;
	}
	for (int i = 0; i < BOARDSIZE; i++) { //przedostatnia kolumna
		placeableMap[BOARDSIZE - 2][i][static_cast<int>(ShipPlacement::V5)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::V5)]--;
		placeableMap[BOARDSIZE - 2][i][static_cast<int>(ShipPlacement::V4)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::V4)]--;
		placeableMap[BOARDSIZE - 2][i][static_cast<int>(ShipPlacement::V3)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::V3)]--;
	}
	for (int i = 0; i < BOARDSIZE; i++) { //przedprzedostatnia kolumna
		placeableMap[BOARDSIZE - 3][i][static_cast<int>(ShipPlacement::V5)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::V5)]--;
		placeableMap[BOARDSIZE - 3][i][static_cast<int>(ShipPlacement::V4)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::V4)]--;
	}
	for (int i = 0; i < BOARDSIZE; i++) { //przedprzedprzedostatnia kolumna
		placeableMap[BOARDSIZE - 4][i][static_cast<int>(ShipPlacement::V5)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::V5)]--;
	}
	for (int i = 0; i < BOARDSIZE; i++) { //ostatni wiersz
		placeableMap[i][BOARDSIZE - 1][static_cast<int>(ShipPlacement::H5)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::H5)]--;
		placeableMap[i][BOARDSIZE - 1][static_cast<int>(ShipPlacement::H4)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::H4)]--;
		placeableMap[i][BOARDSIZE - 1][static_cast<int>(ShipPlacement::H3)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::H3)]--;
		placeableMap[i][BOARDSIZE - 1][static_cast<int>(ShipPlacement::H2)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::H2)]--;
	}
	for (int i = 0; i < BOARDSIZE; i++) { //przedostatni wiersz
		placeableMap[i][BOARDSIZE - 2][static_cast<int>(ShipPlacement::H5)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::H5)]--;
		placeableMap[i][BOARDSIZE - 2][static_cast<int>(ShipPlacement::H4)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::H4)]--;
		placeableMap[i][BOARDSIZE - 2][static_cast<int>(ShipPlacement::H3)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::H3)]--;
	}
	for (int i = 0; i < BOARDSIZE; i++) { //przedprzedostatni wiersz
		placeableMap[i][BOARDSIZE - 3][static_cast<int>(ShipPlacement::H5)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::H5)]--;
		placeableMap[i][BOARDSIZE - 3][static_cast<int>(ShipPlacement::H4)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::H4)]--;
	}
	for (int i = 0; i < BOARDSIZE; i++) { //przedprzedprzedostatni wiersz
		placeableMap[i][BOARDSIZE - 4][static_cast<int>(ShipPlacement::H5)] = false;
		placeableSquares[static_cast<int>(ShipPlacement::H5)]--;
	}
}

//tworzy planszê za pomoc¹ algorytmu 
void PlannerLocalAI::makeBoard() {
	bool repeat = false;
	do {
		resetBoard();
		repeat = !placeShip(5);
		repeat = !placeShip(4);
		repeat = !placeShip(4);
		repeat = !placeShip(3);
		repeat = !placeShip(3);
		repeat = !placeShip(3);
		repeat = !placeShip(2);
		repeat = !placeShip(2);
		repeat = !placeShip(2);
		repeat = !placeShip(2);
	} while (repeat);
}

//zwraca tworzon¹ planszê
BoardLocal& PlannerLocalAI::getBoard() const {
	return board;
}

//umieszcza na planszy statek o rozmiarze size
bool PlannerLocalAI::placeShip(int size) {
	char direction;
	ShipPlacement placement;
	if (randomNumber(2) == 1)
		direction = 'H';
	else
		direction = 'V';
	placement = encode(size, direction);
	if (placeableSquares[static_cast<int>(placement)] == 0)
		return false;
	int pos = randomNumber(placeableSquares[static_cast<int>(placement)]);
	Point point = convert(pos, placement);
	if (place(size, point.x, point.y, direction) == false)
		throw std::exception("PlannerLocalAI::place() tried to place ship in impossible place!"); //nie powinno nigdy wyst¹piæ
	updatePlaceableMap(size, direction, point.x, point.y);
	return true;
}

//zaczyna tworzenie planszy od nowa
void PlannerLocalAI::resetBoard() {
	initializeplaceableMap();
	board.clear();
}

//losuje losow¹ liczbê naturaln¹ z zakresu <1, b>
int PlannerLocalAI::randomNumber(int b) {
	return (rand() % b) + 1;
}

//konwertuje liczbê naturaln¹ "r" na punkt dla danego u³o¿enia statku "sp"
Point PlannerLocalAI::convert(int r, ShipPlacement sp) {
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			if (placeableMap[i][j][static_cast<int>(sp)]) {
				if (--r == 0) {
					return Point{ j, i };
				}
			}
		}
	}
	throw std::exception("PlannerLocalAI::convert() place not found!"); //nie powinno nigdy wyst¹piæ
}

//konwertuje rozmiar i kierunek na odpowiedni ShipPlacement
PlannerLocalAI::ShipPlacement PlannerLocalAI::encode(int size, char direction) {
	if (size == 5) {
		if (direction == 'H') {
			return ShipPlacement::H5;
		}
		else {
			return ShipPlacement::V5;
		}
	}
	else if (size == 4) {
		if (direction == 'H') {
			return ShipPlacement::H4;
		}
		else {
			return ShipPlacement::V4;
		}
	}
	else if (size == 3) {
		if (direction == 'H') {
			return ShipPlacement::H3;
		}
		else {
			return ShipPlacement::V3;
		}
	}
	else {
		if (direction == 'H') {
			return ShipPlacement::H2;
		}
		else {
			return ShipPlacement::V2;
		}
	}
}

//aktualizuje tablicê placeableMap po postawieniu statku
void PlannerLocalAI::updatePlaceableMap(int size, char direction, int x, int y) {
	int ysize = 1;
	int xsize = 1;
	if (direction == 'H')
		xsize = size;
	else
		ysize = size;
	//zerowanie pól granicz¹cych bezpoœrednio
	for (int i = y - 1; i <= y + ysize; i++) {
		for (int j = x - 1; j <= x + xsize; j++) {
			if (i < 0 || i >= BOARDSIZE || j < 0 || j >= BOARDSIZE)
				continue;
			for (int k = 0; k < 8; k++) {
				if (placeableMap[i][j][k]) {
					placeableMap[i][j][k] = false;
					placeableSquares[k]--;
				}
			}
		}
	}
	//zerowanie pól na lewo
	for (int i = y - 1; i <= y + ysize; i++) {
		if (i < 0 || i >= BOARDSIZE) //sprawdzenie wykroczenia w pionie
			continue;
		if (!(x - 2 < 0)) {
			if (placeableMap[i][x - 2][static_cast<int>(encode(2, 'H'))]) {
				placeableMap[i][x - 2][static_cast<int>(encode(2, 'H'))] = false;
				placeableSquares[static_cast<int>(encode(2, 'H'))]--;
			}
			if (placeableMap[i][x - 2][static_cast<int>(encode(3, 'H'))]) {
				placeableMap[i][x - 2][static_cast<int>(encode(3, 'H'))] = false;
				placeableSquares[static_cast<int>(encode(3, 'H'))]--;
			}
			if (placeableMap[i][x - 2][static_cast<int>(encode(4, 'H'))]) {
				placeableMap[i][x - 2][static_cast<int>(encode(4, 'H'))] = false;
				placeableSquares[static_cast<int>(encode(4, 'H'))]--;
			}
			if (placeableMap[i][x - 2][static_cast<int>(encode(5, 'H'))]) {
				placeableMap[i][x - 2][static_cast<int>(encode(5, 'H'))] = false;
				placeableSquares[static_cast<int>(encode(5, 'H'))]--;
			}
		}
		if (!(x - 3 < 0)) {
			if (placeableMap[i][x - 3][static_cast<int>(encode(3, 'H'))]) {
				placeableMap[i][x - 3][static_cast<int>(encode(3, 'H'))] = false;
				placeableSquares[static_cast<int>(encode(3, 'H'))]--;
			}
			if (placeableMap[i][x - 3][static_cast<int>(encode(4, 'H'))]) {
				placeableMap[i][x - 3][static_cast<int>(encode(4, 'H'))] = false;
				placeableSquares[static_cast<int>(encode(4, 'H'))]--;
			}
			if (placeableMap[i][x - 3][static_cast<int>(encode(5, 'H'))]) {
				placeableMap[i][x - 3][static_cast<int>(encode(5, 'H'))] = false;
				placeableSquares[static_cast<int>(encode(5, 'H'))]--;
			}
		}
		if (!(x - 4 < 0)) {
			if (placeableMap[i][x - 4][static_cast<int>(encode(4, 'H'))]) {
				placeableMap[i][x - 4][static_cast<int>(encode(4, 'H'))] = false;
				placeableSquares[static_cast<int>(encode(4, 'H'))]--;
			}
			if (placeableMap[i][x - 4][static_cast<int>(encode(5, 'H'))]) {
				placeableMap[i][x - 4][static_cast<int>(encode(5, 'H'))] = false;
				placeableSquares[static_cast<int>(encode(5, 'H'))]--;
			}
		}
		if (!(x - 5 < 0)) {
			if (placeableMap[i][x - 2][static_cast<int>(encode(5, 'H'))]) {
				placeableMap[i][x - 5][static_cast<int>(encode(5, 'H'))] = false;
				placeableSquares[static_cast<int>(encode(5, 'H'))]--;
			}
		}
	}
	//zerowanie pól na górze
	for (int j = x - 1; j <= x + xsize; j++) {
		if (j < 0 || j >= BOARDSIZE) //sprawdzenie wykroczenia w poziomie
			continue;
		if (!(y - 2 < 0)) {
			if (placeableMap[y - 2][j][static_cast<int>(encode(2, 'V'))]) {
				placeableMap[y - 2][j][static_cast<int>(encode(2, 'V'))] = false;
				placeableSquares[static_cast<int>(encode(2, 'V'))]--;
			}
			if (placeableMap[y - 2][j][static_cast<int>(encode(3, 'V'))]) {
				placeableMap[y - 2][j][static_cast<int>(encode(3, 'V'))] = false;
				placeableSquares[static_cast<int>(encode(3, 'V'))]--;
			}
			if (placeableMap[y - 2][j][static_cast<int>(encode(4, 'V'))]) {
				placeableMap[y - 2][j][static_cast<int>(encode(4, 'V'))] = false;
				placeableSquares[static_cast<int>(encode(4, 'V'))]--;
			}
			if (placeableMap[y - 2][j][static_cast<int>(encode(5, 'V'))]) {
				placeableMap[y - 2][j][static_cast<int>(encode(5, 'V'))] = false;
				placeableSquares[static_cast<int>(encode(5, 'V'))]--;
			}
		}
		if (!(y - 3 < 0)) {
			if (placeableMap[y - 3][j][static_cast<int>(encode(3, 'V'))]) {
				placeableMap[y - 3][j][static_cast<int>(encode(3, 'V'))] = false;
				placeableSquares[static_cast<int>(encode(3, 'V'))]--;
			}
			if (placeableMap[y - 3][j][static_cast<int>(encode(4, 'V'))]) {
				placeableMap[y - 3][j][static_cast<int>(encode(4, 'V'))] = false;
				placeableSquares[static_cast<int>(encode(4, 'V'))]--;
			}
			if (placeableMap[y - 3][j][static_cast<int>(encode(5, 'V'))]) {
				placeableMap[y - 3][j][static_cast<int>(encode(5, 'V'))] = false;
				placeableSquares[static_cast<int>(encode(5, 'V'))]--;
			}
		}
		if (!(y - 4 < 0)) {
			if (placeableMap[y - 4][j][static_cast<int>(encode(4, 'V'))]) {
				placeableMap[y - 4][j][static_cast<int>(encode(4, 'V'))] = false;
				placeableSquares[static_cast<int>(encode(4, 'V'))]--;
			}
			if (placeableMap[y - 4][j][static_cast<int>(encode(5, 'V'))]) {
				placeableMap[y - 4][j][static_cast<int>(encode(5, 'V'))] = false;
				placeableSquares[static_cast<int>(encode(5, 'V'))]--;
			}
		}
		if (!(y - 5 < 0)) {
			if (placeableMap[y - 5][j][static_cast<int>(encode(5, 'V'))]) {
				placeableMap[y - 5][j][static_cast<int>(encode(5, 'V'))] = false;
				placeableSquares[static_cast<int>(encode(5, 'V'))]--;
			}
		}
	}
}