#include "Board.h"

//konstruktor
Board::Board(int _BOARDSIZE) : BOARDSIZE(_BOARDSIZE), unsunkShips(0) {
	shotMap = new bool*[BOARDSIZE];
	for (int i = 0; i < BOARDSIZE; i++) {
		shotMap[i] = new bool[BOARDSIZE];
		shotMap[i] = false;
	}
}

//destruktor
Board::~Board() {
	for (int i = 0; i < BOARDSIZE; i++) {
		delete[] shotMap[i];
	}
	delete[] shotMap;
}

//zwraca wartoœæ pola unsunkShips
bool Board::getUnsunkShips() {
	return unsunkShips;
}

//zwraca listê statków na planszy
std::list<Board::ShipInfo> Board::getList() {
	return list;
}

//zwraca tablicê zawieraj¹c¹ informacje o postrzelonych polach
bool** Board::getShotMap() {
	return shotMap;
}