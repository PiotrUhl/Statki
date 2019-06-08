#include "Board.h"

//konstruktor
Board::Board(int _BOARDSIZE, IUserInterface& _outInterface) : BOARDSIZE(_BOARDSIZE), outInterface(_outInterface), unsunkShips(0), shotMap(10, std::vector<ShotResult>(10, ShotResult::NONE)) {}

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
std::vector<std::vector<ShotResult>> Board::getShotMap() {
	return shotMap;
}