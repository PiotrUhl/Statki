#pragma once
#include "structs.hpp"
#include <memory> //std::shared_ptr

class Ship;

class Square {
private:
	bool shooted; //czy strzelono w pole
	ShotResult state; //stan pola
	std::shared_ptr<Ship> ship; //statek znajduj¹cy siê na danym polu; nullptr jeœli pole puste
public:
	//konstruktor
	Square();
	//destruktor
	~Square();
	//przeci¹¿enie operatora == dla nullptr
	bool operator==(std::nullptr_t) const;
	//przeci¹¿enie operatora != dla nullptr
	bool operator!=(std::nullptr_t) const;
	//umieszcza w polu statek 'newShip'
	void set(std::shared_ptr<Ship>& newShip);
	//strzelono w pole; zwraca rezultat
	ShotResult shot();
	//zmienia stan fragmentu statku w polu na "zatopiony"
	void setToSunk();
	//usuwa statek le¿¹cy na polu; zwraca false je¿eli pole ju¿ puste
	bool removeShip();
	//przywraca domyœlny stan obiektu
	void reset();
	//zwraca shooted
	bool getShooted() const;
	//zwraca rozmiar statku le¿¹cego na danym polu (b¹dŸ 0 jeœli pole puste)
	int getSize() const;
	//zwraca czy statek na danym polu jest zatopiony
	bool getSunk() const;
	//zwraca informacje o statku le¿¹cym na polu
	ShipInfo getShipInfo() const;
};