#pragma once
#include "Board.h"
#include "Square.h"

class BoardLocal : public Board {
private:
	boost::multi_array<Square, 2> board; //plansza
	std::list<std::shared_ptr<Ship>> list; //lista statk�w
public:
	//konstruktor
	BoardLocal();
	//destruktor
	~BoardLocal();
	//przeci��ony operator []
	boost::multi_array<Square, 2>::array_view<1>::type operator[](size_t);
	//umieszcza statkek o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
	bool placeShip(int shipSize, int x, int y, char direction);
	//usuwa statkek z pola ("x", "y")
	bool removeShip(int x, int y);
	//zwraca obraz planszy
	boost::multi_array<unsigned char, 2> getImage() const override;
	//zwraca obraz pola 'point'
	unsigned char getSquareImage(Point point) const override;
	//strzela w pole planszy o wsp�rz�dnych (x, y); zwraca rezultat
	ShotResult shot(int x, int y) override;
	//zwraca list� informacji o wszystkich statkach na planszy
	std::list<ShipInfo> getShipList() const; //zaimplementowa� po przeniesieniu listy statk�w do klas potomnych
	//zwraca informacje o statku le��cym na polu 'point'
	ShipInfo getSquareShip(Point point) const override;
	//usuwa ca�� zawarto�� planszy
	void clear();
private:
	//okre�la kierunek statku le��cego na polu  ("x", "y")
	char findDirection(int x, int y) const;
};