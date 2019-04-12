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
	//strzelono w pole; zwraca rezultat; rzuca wyj¹tek std::logic_error("Square already shooted") je¿eli pole ju¿ postrzelone
	ShotResult shot();
	//zmienia stan fragmentu statku w polu na "zatopiony"
	void setToSunk();
};