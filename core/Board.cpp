#include "Board.h"

//konstruktor
Board::Board(int _BOARDSIZE) : BOARDSIZE(_BOARDSIZE), unsunkShips(0) {}

//destruktor
Board::~Board() {}

//zwraca wartoœæ pola unsunkShips
bool Board::getUnsunkShips() {
	return unsunkShips;
}