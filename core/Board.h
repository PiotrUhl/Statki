#pragma once
#include "Ship.h"
#include "structs.hpp" //ShipInfo, ShotResult
#include <list> //std::list
#include <vector> //std::vector

class IUserInterface;

class Board {
private:
	static int lastId; //najwy¿sze id planszy
	int id; //numer identyfikacyjny planszy
protected:
	const int BOARDSIZE; //rozmiar planszy
	int unsunkShips; //liczba niezatopnionych statków
	std::list<ShipInfo> list; //lista statków
	std::vector<std::vector<ShotResult>> shotMap; //mapa strza³ów
	IUserInterface& outInterface; //interfejs do wypisywania planszy
public:
	//konstruktor
	Board(int _BOARDSIZE, IUserInterface&);
	//destruktor
	virtual ~Board();
	//zwraca numer identyfikacyjny planszy
	int getId();
	//zwraca wartoœæ pola unsunkShips
	bool getUnsunkShips();
	//zwraca listê statków na planszy
	std::list<ShipInfo> getList();
	//zwraca tablicê zawieraj¹c¹ informacje o postrzelonych polach
	std::vector<std::vector<ShotResult>> getShotMap();
	//strzela w pole planszy o wspó³rzêdnych (x, y); zwraca rezultat
	virtual ShotResult shot(int x, int y) = 0;
};