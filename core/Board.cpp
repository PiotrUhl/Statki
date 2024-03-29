#include "Board.h"

//konstruktor
Board::Board() : shipCount(0), unsunkShips(0), shotMap(boost::extents[BOARDSIZE][BOARDSIZE]), lastShotPoint(Point{ BOARDSIZE, BOARDSIZE }), lastShotResult(ShotResult::NONE) {
	for (auto k : shotMap)
		for (auto l : k)
			l = ShotResult::NONE;
}

//destruktor
Board::~Board() {}

//zwraca warto�� pola unsunkShips
bool Board::getUnsunkShips() {
	return unsunkShips;
}

//zwraca tablic� zawieraj�c� informacje o postrzelonych polach
boost::multi_array<ShotResult, 2> Board::getShotMap() const {
	return shotMap;
}

//zwraca informacj� o strzale w pole 'point' na planszy 'boardId'
ShotResult Board::getSquareShot(Point point) const {
	return shotMap[point.y][point.x];
}

//zwraca lastShotPoint
Point Board::getLastShotPoint() const {
	return lastShotPoint;
}

//zwraca lastShotResult
ShotResult Board::getLastShotResult() const {
	return lastShotResult;
}

//zwraca liczb� statk�w na planszy 'boardId'
int Board::getShipCount() const {
	return shipCount;
}