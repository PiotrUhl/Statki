#pragma once
#include "Ship.h"
#include <list>
#include <memory>

class Board {
public:
	enum ShotResult { SUNK, HIT, MISS }; //rezultat strza³u
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
	int unsunkShips; //liczba niezatopnionych statków
	std::list<ShipInfo> list; //lista statków
	bool** shotMap; //mapa strza³ów
public:
	//konstruktor
	Board(int _BOARDSIZE);
	//destruktor
	virtual ~Board();
	//zwraca wartoœæ pola unsunkShips
	bool getUnsunkShips();
	//zwraca listê statków na planszy
	std::list<ShipInfo> getList();
	//zwraca tablicê zawieraj¹c¹ informacje o postrzelonych polach
	bool** getShotMap();
	//strzela w pole planszy o wspó³rzêdnych (x, y); zwraca rezultat
	virtual ShotResult shot(int x, int y) = 0;
};