#pragma once
#include <memory> //std::shared_ptr

class Ship;

class Square {
private:
	enum ShotResult { SUNK, HIT, MISS }; //rezultat strza�u
	std::shared_ptr<Ship> ship; //statek znajduj�cy si� na danym polu; nullptr je�li pole puste
public:
	//konstruktor
	Square();
	//destruktor
	~Square();
	//strzelono w pole; zwraca rezultat
	ShotResult shot();
};