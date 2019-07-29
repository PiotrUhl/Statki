#include "Ship.h"
#include "Square.h"
//konstruktor
Ship::Ship(int _size) : size(_size), damage(0), sunk(false) {}

//destruktor
Ship::~Ship() {}

//trafiono w statek; zwraca czy zatopiono statek
bool Ship::hit() {
	if (sunk)
		throw std::logic_error("Ship already sunk");
	damage++;
	if (checkSunk()) {
		for (auto k : location)
			 k->setToSunk(); //informuje pola na planszy o zatopieniu statku
		return true;
	}
	else
		return false;
}

//usuwa statek z planszy
void Ship::remove() {
	for (auto k : location)
		k->reset(); //usuwa statek z pól na których siê znajduje
}

//zwraca size
int Ship::getSize() const {
	return size;
}
//zwraca sunk
bool Ship::getSunk() const {
	return sunk;
}

//dodaje informacje o polu na którym le¿y statek
void Ship::addLocation(Square* square) {
	location.push_back(square);
}

//sprawdza czy statek jest zatopiony
bool Ship::checkSunk() {
	if (damage < size)
		return false;
	else
		return true;
}

//zwraca strukturê z informacjami o statku
ShipInfo Ship::getShipInfo() const {
	ShipInfo ret;
	ret.size = size;
	ret.x = startingPoint.x;
	ret.y = startingPoint.y;;
	ret.direction = direction;
	ret.sunk = sunk;
	return ret;
}