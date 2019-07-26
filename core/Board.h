#pragma once
#include "Ship.h"
#include "structs.hpp" //ShipInfo, ShotResult
#include <list> //std::list
#pragma warning(push, 0)
#include <boost/multi_array.hpp> //boost::multi_array
#pragma warning(pop)

class Board {
private:
	static int lastId; //najwy¿sze id planszy
	int id; //numer identyfikacyjny planszy
protected:
	int unsunkShips; //liczba niezatopnionych statków
	std::list<ShipInfo> list; //lista statków
	boost::multi_array<ShotResult, 2> shotMap; //mapa strza³ów
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
	boost::multi_array<ShotResult, 2> getShotMap();
	//strzela w pole planszy o wspó³rzêdnych (x, y); zwraca rezultat
	virtual ShotResult shot(int x, int y) = 0;
	//zwraca obraz planszy
	virtual boost::multi_array<char, 2> getImage() = 0;
};