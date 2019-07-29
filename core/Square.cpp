#include "Square.h"

//konstruktor
Square::Square() : shooted(false), state(ShotResult::NONE) {}

//destruktor
Square::~Square() {}

//przeci¹¿enie operatora == dla nullptr
bool Square::operator==(std::nullptr_t) {
	if (ship == nullptr)
		return true;
	else
		return false;
}

//przeci¹¿enie operatora != dla nullptr
bool Square::operator!=(std::nullptr_t) {
	if (ship == nullptr)
		return false;
	else
		return true;
}

//umieszcza w polu statek 'newShip'
void Square::set(std::shared_ptr<Ship>& newShip) {
	ship = newShip;
}

#include "Ship.h" //ship->hit()
//strzelono w pole; zwraca rezultat; rzuca wyj¹tek std::logic_error("Square already shooted") je¿eli pole ju¿ postrzelone
ShotResult Square::shot() {
	if (shooted)
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

//usuwa statek le¿¹cy na polu; zwraca false je¿eli pole ju¿ puste
bool Square::removeShip() {
	if (ship == nullptr)
		return false;
	else {
		ship->remove();
		return true;
	}
}

//przywraca domyœlny stan obiektu
void Square::reset() {
	ship = nullptr;
	shooted = false;
}

//zwraca shooted
bool Square::getShooted() const {
	return shooted;
}
//zwraca rozmiar statku le¿¹cego na danym polu (b¹dŸ 0 jeœli pole puste)
int Square::getSize() const {
	if (ship == nullptr)
		return 0;
	else
		return ship->getSize();
}
//zwraca czy statek na danym polu jest zatopiony
bool Square::getSunk() const {
	if (ship == nullptr)
		return false;
	else
		return ship->getSunk();
}

//zwraca informacje o statku le¿¹cym na polu
ShipInfo Square::getShipInfo() const {
	if (ship == nullptr)
		return ShipInfo{0,0,0,0,0};
	else
		return ship->getShipInfo();
}