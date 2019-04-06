#include "Square.h"

//konstruktor
Square::Square() {}

//destruktor
Square::~Square() {}

//strzelono w pole; zwraca rezultat
Square::ShotResult Square::shot() {
	return ShotResult::MISS; //temp
}

//zmienia stan fragmentu statku w polu na "zatopiony"
void Square::setToSunk() {} //temp