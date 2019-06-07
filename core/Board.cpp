#include "Board.h"

//konstruktor
Board::Board(int _BOARDSIZE) : BOARDSIZE(_BOARDSIZE), unsunkShips(0), shotMap(10, std::vector<bool>(10)) {}

//destruktor
Board::~Board() {}

//zwraca wartoœæ pola unsunkShips
bool Board::getUnsunkShips() {
	return unsunkShips;
}

//zwraca listê statków na planszy
std::list<Board::ShipInfo> Board::getList() {
	return list;
}

//zwraca tablicê zawieraj¹c¹ informacje o postrzelonych polach
std::vector<std::vector<bool>> Board::getShotMap() {
	return shotMap;
}