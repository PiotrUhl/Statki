#include "Ship.h"

//konstruktor
Ship::Ship(int _size) : size(_size), location(size) {}

//destruktor
Ship::~Ship() {}

//trafiono w statek; zwraca czy zatopiono statek
bool Ship::hit() {
	return false; //temp
}