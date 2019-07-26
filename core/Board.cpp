#include "Board.h"

//najwy¿sze id planszy
int Board::lastId = 0;

//konstruktor
Board::Board() : id(++lastId), unsunkShips(0), shotMap(boost::extents[BOARDSIZE][BOARDSIZE]), lastShotPoint(Point{ BOARDSIZE, BOARDSIZE }), lastShotResult(ShotResult::NONE) {
	for (auto k : shotMap)
		for (auto l : k)
			l = ShotResult::NONE;
}

//destruktor
Board::~Board() {}

//zwraca numer identyfikacyjny planszy
int Board::getId() {
	return id;
}

//zwraca wartoœæ pola unsunkShips
bool Board::getUnsunkShips() {
	return unsunkShips;
}

//zwraca listê statków na planszy
std::list<ShipInfo> Board::getList() {
	return list;
}

//zwraca tablicê zawieraj¹c¹ informacje o postrzelonych polach
boost::multi_array<ShotResult, 2> Board::getShotMap() {
	return shotMap;
}

//zwraca lastShotPoint
Point Board::getLastShotPoint() const {
	return lastShotPoint;
}

//zwraca lastShotResult
ShotResult Board::getLastShotResult() const {
	return lastShotResult;
}