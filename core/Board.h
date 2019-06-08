#pragma once
#include "Ship.h"
#include "structs.hpp" //ShipInfo, ShotResult
#include <list> //std::list
#include <vector> //std::vector

class IUserInterface;

class Board {
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