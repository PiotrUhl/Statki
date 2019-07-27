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
	static int lastId; //najwy�sze id planszy
	int id; //numer identyfikacyjny planszy
protected:
	int unsunkShips; //liczba niezatopnionych statk�w
	std::list<ShipInfo> list; //lista statk�w
	boost::multi_array<ShotResult, 2> shotMap; //mapa strza��w
	Point lastShotPoint; //miejsce ostatniego strza�u w plansz�; (BOARDSIZE, BOARDSIZE) je�eli nie strzelano
	ShotResult lastShotResult; //wynik ostatniego strza�u w plansz�
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
	boost::multi_array<ShotResult, 2> getShotMap() const;
	//zwraca informacj� o strzale w pole 'point' na planszy 'boardId'
	ShotResult getSquareShot(Point point) const;
	//zwraca lastShotPoint
	Point getLastShotPoint() const;
	//zwraca lastShotResult
	ShotResult getLastShotResult() const;
	//strzela w pole planszy o wsp�rz�dnych (x, y); zwraca rezultat
	virtual ShotResult shot(int x, int y) = 0;
	//zwraca obraz planszy
	virtual boost::multi_array<char, 2> getImage() = 0; //todo: przerobi� na unsigned char
	//zwraca obraz pola 'point'
	virtual unsigned char getSquareImage(Point point) = 0;
};