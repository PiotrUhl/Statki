#include "Ship.h"
#include "Square.h"
//konstruktor
Ship::Ship(int _size) : size(_size), location(size) {}

//destruktor
Ship::~Ship() {}

//trafiono w statek; zwraca czy zatopiono statek
bool Ship::hit() {
	damage++;
	if (checkSunk()) {
		for (auto k : location) {
			 k->setToSunk(); //informuje pola na planszy o zatopieniu statku
		}
		return true;
	}
	else {
		return false;
	}
}

//sprawdza czy statek jest zatopiony
bool Ship::checkSunk() {
	if (damage < size)
		return false;
	else
		return true;
}