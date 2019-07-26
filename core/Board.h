#pragma once
#include "Ship.h"
#include "Point.hpp"
#include "structs.hpp" //ShipInfo, ShotResult
#include <list> //std::list
#include <array> //std::array

class Board {
private:
	static int lastId; //najwy¿sze id planszy
	int id; //numer identyfikacyjny planszy
protected:
	int unsunkShips; //liczba niezatopnionych statków
	std::list<ShipInfo> list; //lista statków
	std::array<std::array<ShotResult, BOARDSIZE>, BOARDSIZE> shotMap; //mapa strza³ów
	Point lastShotPoint; //miejsce ostatniego strza³u w planszê; (BOARDSIZE, BOARDSIZE) je¿eli nie strzelano
public:
	//konstruktor
	Board();
	//destruktor
	virtual ~Board();
	//zwraca numer identyfikacyjny planszy
	int getId();
	//zwraca wartoœæ pola unsunkShips
	bool getUnsunkShips();
	//zwraca listê statków na planszy
	std::list<ShipInfo> getList();
	//zwraca tablicê zawieraj¹c¹ informacje o postrzelonych polach
	std::array<std::array<ShotResult, BOARDSIZE>, BOARDSIZE> getShotMap();
	//zwraca lastShotPoint
	Point getLastShotPoint() const;
	//strzela w pole planszy o wspó³rzêdnych (x, y); zwraca rezultat
	virtual ShotResult shot(int x, int y) = 0;
};