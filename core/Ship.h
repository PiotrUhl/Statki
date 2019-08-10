#pragma once
#include "structs.hpp" //Point, Direction
#include <vector> //std::vector

class Square;

class Ship {
private:
	const int size; //rozmiar statku (2..5)
	std::vector<Square*> location; //po�o�enie statku (pola na kt�rych le�y)
	int damage; //ilo�� trafie� przyj�tych przez statek
	Point startingPoint; //punkt pocz�tkowy statku (lewy g�rny)
	Direction direction; //kierunek po�o�enia statku
	bool sunk; //czy statek jest zatopiony
public:
	//konstruktor
	Ship(int _size, Point _point, Direction _direction);
	//destruktor
	~Ship();
	//trafiono w statek; zwraca czy zatopiono statek
	bool hit();
	//usuwa statek z planszy
	void remove();
	//zwraca size
	int getSize() const;
	//zwraca punkt pocz�tkowy
	Point getPoint() const;
	//zwraca sunk
	bool getSunk() const;
	//zwraca direction
	Direction getDirection() const;
	//dodaje informacje o polu na kt�rym le�y statek
	void addLocation(Square*);
	//zwraca struktur� z informacjami o statku
	ShipInfo getShipInfo() const;
private:
	//sprawdza czy statek jest zatopiony
	bool checkSunk();
};