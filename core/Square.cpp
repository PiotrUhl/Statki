#include "Square.h"

//konstruktor
Square::Square() : shooted(false) {}

//destruktor
Square::~Square() {}

//umieszcza w polu statek 'newShip'
void Square::set(std::shared_ptr<Ship>& newShip) {
	ship = newShip;
}

#include "Ship.h" //ship->hit()
//strzelono w pole; zwraca rezultat; rzuca wyj¹tek std::logic_error("Square already shooted") je¿eli pole ju¿ postrzelone
Square::ShotResult Square::shot() {
	if (shooted == true)
		throw std::logic_error("Square already shot");
	shooted = true;
	if (ship == nullptr) {
		state = ShotResult::MISS;
		return ShotResult::MISS;
	}
	else {
		if (ship->hit() == false) {
			state = ShotResult::HIT;
			return ShotResult::HIT;
		}
		else {
			//state = ShotResult::SUNK; //realizuje to metoda ship::hit()
			return ShotResult::SUNK;
		}
	}
}

//zmienia stan fragmentu statku w polu na "zatopiony"
void Square::setToSunk() {
	state = ShotResult::SUNK;
}