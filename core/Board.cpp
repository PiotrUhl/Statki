#include "Board.h"

//najwy�sze id planszy
int Board::lastId = 0;

//konstruktor
Board::Board() : id(++lastId), unsunkShips(0) {
	for (auto k : shotMap)
		k.fill(ShotResult::NONE);
}

//destruktor
Board::~Board() {}

//zwraca numer identyfikacyjny planszy
int Board::getId() {
	return id;
}

//zwraca warto�� pola unsunkShips
bool Board::getUnsunkShips() {
	return unsunkShips;
}

//zwraca list� statk�w na planszy
std::list<ShipInfo> Board::getList() {
	return list;
}

//zwraca tablic� zawieraj�c� informacje o postrzelonych polach
std::array<std::array<ShotResult, BOARDSIZE>, BOARDSIZE> Board::getShotMap() {
	return shotMap;
}