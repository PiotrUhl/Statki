#pragma once
#include "Ship.h"
#include "Point.hpp"
#include "structs.hpp" //ShipInfo, ShotResult
#include <list> //std::list
#include <array> //std::array

class Board {
private:
	static int lastId; //najwy�sze id planszy
	int id; //numer identyfikacyjny planszy
protected:
	int unsunkShips; //liczba niezatopnionych statk�w
	std::list<ShipInfo> list; //lista statk�w
	std::array<std::array<ShotResult, BOARDSIZE>, BOARDSIZE> shotMap; //mapa strza��w
	Point lastShotPoint; //miejsce ostatniego strza�u w plansz�; (BOARDSIZE, BOARDSIZE) je�eli nie strzelano
public:
	//konstruktor
	Board();
	//destruktor
	virtual ~Board();
	//zwraca numer identyfikacyjny planszy
	int getId();
	//zwraca warto�� pola unsunkShips
	bool getUnsunkShips();
	//zwraca list� statk�w na planszy
	std::list<ShipInfo> getList();
	//zwraca tablic� zawieraj�c� informacje o postrzelonych polach
	std::array<std::array<ShotResult, BOARDSIZE>, BOARDSIZE> getShotMap();
	//zwraca lastShotPoint
	Point getLastShotPoint() const;
	//strzela w pole planszy o wsp�rz�dnych (x, y); zwraca rezultat
	virtual ShotResult shot(int x, int y) = 0;
};