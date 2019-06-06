#pragma once
#include "Ship.h"
#include <list>
#include <memory>

class Board {
public:
	enum ShotResult { SUNK, HIT, MISS }; //rezultat strza�u
protected:
	struct ShipInfo {
		int size;
		int x;
		int y;
		char direction;
		bool sunk;
		ShipInfo(int _size, int _x, int _y, char _direction, bool _sunk = 0) : size(_size), x(_x), y(_y), direction(_direction), sunk(_sunk) {}
	};
	const int BOARDSIZE; //rozmiar planszy
	int unsunkShips; //liczba niezatopnionych statk�w
	std::list<ShipInfo> list; //lista statk�w
	bool** shotMap; //mapa strza��w
public:
	//konstruktor
	Board(int _BOARDSIZE);
	//destruktor
	virtual ~Board();
	//zwraca warto�� pola unsunkShips
	bool getUnsunkShips();
	//zwraca list� statk�w na planszy
	std::list<ShipInfo> getList();
	//zwraca tablic� zawieraj�c� informacje o postrzelonych polach
	bool** getShotMap();
	//strzela w pole planszy o wsp�rz�dnych (x, y); zwraca rezultat
	virtual ShotResult shot(int x, int y) = 0;
};