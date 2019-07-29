#pragma once
#include "Ship.h"
#include "structs.hpp" //ShipInfo, ShotResult, Point
#include <list> //std::list
#pragma warning(push, 0)
#include <boost/multi_array.hpp> //boost::multi_array
#pragma warning(pop)

class Board {
private:
	static int lastId; //najwy¿sze id planszy
	int id; //numer identyfikacyjny planszy
protected:
	int shipCount; //liczba statków na planszy //todo: zaimplementowaæ obs³ugê
	int unsunkShips; //liczba niezatopnionych statków
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
	virtual boost::multi_array<unsigned char, 2> getImage() = 0;
	//zwraca obraz pola 'point'
	virtual unsigned char getSquareImage(Point point) = 0;
	//zwraca listê informacji o wszystkich statkach na planszy
	virtual std::list<ShipInfo> getShipList() const = 0;
	//zwraca informacje o statku le¿¹cym na polu 'point' na planszy 'boardId'
	virtual ShipInfo getSquareShip(Point point) const = 0;
	//zwraca liczbê statków na planszy 'boardId'
	int getShipCount() const;
};