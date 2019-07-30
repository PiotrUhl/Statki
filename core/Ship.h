#pragma once
#include "structs.hpp"
#include <vector> //std::vector

class Square;

class Ship {
private:
	const int size; //rozmiar statku (2..5)
	std::vector<Square*> location; //po³o¿enie statku (pola na których le¿y)
	int damage; //iloœæ trafieñ przyjêtych przez statek
	Point startingPoint; //punkt pocz¹tkowy statku (lewy górny)
	char direction; //kierunek po³o¿enia statku {H, V}
	bool sunk; //czy statek jest zatopiony
public:
	//konstruktor
	Ship(int _size, Point _point, char _direction);
	//destruktor
	~Ship();
	//trafiono w statek; zwraca czy zatopiono statek
	bool hit();
	//usuwa statek z planszy
	void remove();
	//zwraca size
	int getSize() const;
	//zwraca punkt pocz¹tkowy
	Point getPoint() const;
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