#include "Board.h"

//konstruktor
Board::Board(int _BOARDSIZE) : BOARDSIZE(_BOARDSIZE), unsunkShips(0), shotMap(10, std::vector<bool>(10)) {}

//destruktor
Board::~Board() {}

//zwraca warto�� pola unsunkShips
bool Board::getUnsunkShips() {
	return unsunkShips;
}

//zwraca list� statk�w na planszy
std::list<Board::ShipInfo> Board::getList() {
	return list;
}

//zwraca tablic� zawieraj�c� informacje o postrzelonych polach
std::vector<std::vector<bool>> Board::getShotMap() {
	return shotMap;
}