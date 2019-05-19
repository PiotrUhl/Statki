#pragma once
#include <memory> //std::shared_ptr

class Ship;

class Square {
private:
	bool shooted; //czy strzelono w pole
	enum class ShotResult { SUNK, HIT, MISS } state; //stan pola po strzale
	std::shared_ptr<Ship> ship; //statek znajduj¹cy siê na danym polu; nullptr jeœli pole puste
public:
	//konstruktor
	Square();
	//destruktor
	~Square();
	//przeci¹¿enie operatora != dla nullptr
	bool operator!=(std::nullptr_t);
	//umieszcza w polu statek 'newShip'
	void set(std::shared_ptr<Ship>& newShip);
	//strzelono w pole; zwraca rezultat; rzuca wyj¹tek std::logic_error("Square already shooted") je¿eli pole ju¿ postrzelone
	ShotResult shot();
	//zmienia stan fragmentu statku w polu na "zatopiony"
	void setToSunk();
	//usuwa statek le¿¹cy na polu; zwraca false je¿eli pole ju¿ puste
	bool removeShip();
	//przywraca domyœlny stan obiektu
	void reset();
};