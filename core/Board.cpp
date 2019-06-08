#include "Board.h"

//najwy�sze id planszy
int Board::lastId = 0;

//konstruktor
Board::Board(int _BOARDSIZE, IUserInterface& _outInterface) : BOARDSIZE(_BOARDSIZE), id(lastId++), outInterface(_outInterface), unsunkShips(0), shotMap(10, std::vector<ShotResult>(10, ShotResult::NONE)) {}

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
std::list<Board::ShipInfo> Board::getList() {
	return list;
}

//zwraca tablic� zawieraj�c� informacje o postrzelonych polach
std::vector<std::vector<ShotResult>> Board::getShotMap() {
	return shotMap;
}