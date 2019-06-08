#pragma once
#include "Ship.h"
//#include "IUserInterface.h"
#include "enums.hpp"
#include <list>
#include <vector>

class IUserInterface;

class Board {
public:
	struct ShipInfo {
		int size;
		int x;
		int y;
		char direction;
		bool sunk;
		ShipInfo() = default;
		ShipInfo(int _size, int _x, int _y, char _direction, bool _sunk = 0) : size(_size), x(_x), y(_y), direction(_direction), sunk(_sunk) {}
	};
private:
	static int lastId; //najwy�sze id planszy
	int id; //numer identyfikacyjny planszy
protected:
	const int BOARDSIZE; //rozmiar planszy
	int unsunkShips; //liczba niezatopnionych statk�w
	std::list<ShipInfo> list; //lista statk�w
	std::vector<std::vector<ShotResult>> shotMap; //mapa strza��w
	IUserInterface& outInterface; //interfejs do wypisywania planszy
public:
	//konstruktor
	Board(int _BOARDSIZE, IUserInterface&);
	//destruktor
	virtual ~Board();
	//zwraca numer identyfikacyjny planszy
	int getId();
	//zwraca warto�� pola unsunkShips
	bool getUnsunkShips();
	//zwraca list� statk�w na planszy
	std::list<ShipInfo> getList();
	//zwraca tablic� zawieraj�c� informacje o postrzelonych polach
	std::vector<std::vector<ShotResult>> getShotMap();
	//strzela w pole planszy o wsp�rz�dnych (x, y); zwraca rezultat
	virtual ShotResult shot(int x, int y) = 0;
};