#pragma once
#include "Ship.h"
#include "structs.hpp" //ShipInfo, ShotResult, Point
#include <list> //std::list
#pragma warning(push, 0)
#include <boost/multi_array.hpp> //boost::multi_array
#pragma warning(pop)

class Board {
protected:
	int shipCount; //liczba statk�w na planszy
	int unsunkShips; //liczba niezatopnionych statk�w
	boost::multi_array<ShotResult, 2> shotMap; //mapa strza��w
	Point lastShotPoint; //miejsce ostatniego strza�u w plansz�; (BOARDSIZE, BOARDSIZE) je�eli nie strzelano
	ShotResult lastShotResult; //wynik ostatniego strza�u w plansz�
public:
	//konstruktor
	Board();
	//destruktor
	virtual ~Board();

	//zwraca warto�� pola unsunkShips
	bool getUnsunkShips();
	//zwraca tablic� zawieraj�c� informacje o postrzelonych polach
	boost::multi_array<ShotResult, 2> getShotMap() const;
	//zwraca informacj� o strzale w pole 'point'
	ShotResult getSquareShot(Point point) const;
	//zwraca lastShotPoint
	Point getLastShotPoint() const;
	//zwraca lastShotResult
	ShotResult getLastShotResult() const;
	//strzela w pole 'point'; zwraca rezultat
	virtual ShotResult shot(Point point) = 0;
	//zwraca obraz planszy
	virtual boost::multi_array<unsigned char, 2> getImage() const = 0;
	//zwraca obraz pola 'point'
	virtual unsigned char getSquareImage(Point point) const = 0;
	//zwraca list� informacji o wszystkich statkach na planszy
	virtual std::list<ShipInfo> getShipList() const = 0;
	//zwraca informacje o statku le��cym na polu 'point'
	virtual ShipInfo getSquareShip(Point point) const = 0;
	//zwraca liczb� statk�w na planszy
	int getShipCount() const;
};