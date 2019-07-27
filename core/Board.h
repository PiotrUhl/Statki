#pragma once
#include "Ship.h"
#include "Point.hpp"
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
	Point lastShotPoint; //miejsce ostatniego strza³u w planszê; (BOARDSIZE, BOARDSIZE) je¿eli nie strzelano
	ShotResult lastShotResult; //wynik ostatniego strza³u w planszê
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
	boost::multi_array<ShotResult, 2> getShotMap() const;
	//zwraca informacjê o strzale w pole 'point' na planszy 'boardId'
	ShotResult getSquareShot(Point point) const;
	//zwraca lastShotPoint
	Point getLastShotPoint() const;
	//zwraca lastShotResult
	ShotResult getLastShotResult() const;
	//strzela w pole planszy o wspó³rzêdnych (x, y); zwraca rezultat
	virtual ShotResult shot(int x, int y) = 0;
	//zwraca obraz planszy
	virtual boost::multi_array<char, 2> getImage() = 0; //todo: przerobiæ na unsigned char
	//zwraca obraz pola 'point'
	virtual unsigned char getSquareImage(Point point) = 0;
};