#pragma once
#include "structs.hpp"
#include "Point.hpp"
#include <vector> //std::vector

class Square;

class Ship {
private:
	const int size; //rozmiar statku (2..5)
	std::vector<Square*> location; //po³o¿enie statku (pola na których le¿y)
	int damage; //iloœæ trafieñ przyjêtych przez statek
	Point startingPoint; //undone: punkt pocz¹tkowy statku
	char direction; //undone: kierunek statku
	bool sunk; //czy statek jest zatopiony
public:
	//konstruktor
	Ship(int _size);
	//destruktor
	~Ship();
	//trafiono w statek; zwraca czy zatopiono statek
	bool hit();
	//usuwa statek z planszy
	void remove();
	//zwraca size
	int getSize() const;
	//zwraca sunk
	bool getSunk() const;
	//dodaje informacje o polu na którym le¿y statek
	void addLocation(Square*);
	//zwraca strukturê z informacjami o statku
	ShipInfo getShipInfo() const;
private:
	//sprawdza czy statek jest zatopiony
	bool checkSunk();
};