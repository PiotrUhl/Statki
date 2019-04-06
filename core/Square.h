#pragma once
#include <memory> //std::shared_ptr

class Ship;

class Square {
private:
	enum ShotResult { SUNK, HIT, MISS }; //rezultat strza³u
	std::shared_ptr<Ship> ship; //statek znajduj¹cy siê na danym polu; nullptr jeœli pole puste
public:
	//konstruktor
	Square();
	//destruktor
	~Square();
	//strzelono w pole; zwraca rezultat
	ShotResult shot();
};