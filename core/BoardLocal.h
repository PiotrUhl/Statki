#pragma once
#include "Board.h"
#include "Square.h"

class BoardLocal : public Board {
private:
	boost::multi_array<Square, 2> board; //plansza
	std::list<std::shared_ptr<Ship>> list; //lista statków
public:
	//konstruktor
	BoardLocal();
	//destruktor
	~BoardLocal();
	//przeci¹¿ony operator []
	boost::multi_array<Square, 2>::array_view<1>::type operator[](size_t);
	Square& operator[](Point);
	//umieszcza statkek o rozmiarze "shipSize" w polu 'point', w kierunku direction; zwraca rezultat
	bool placeShip(int shipSize, Point point, Direction direction);
	//usuwa statkek z pola 'point;
	bool removeShip(Point point);
	//zwraca obraz planszy
	boost::multi_array<unsigned char, 2> getImage() const override;
	//zwraca obraz pola 'point'
	unsigned char getSquareImage(Point point) const override;
	//strzela w pole 'point'; zwraca rezultat
	ShotResult shot(Point point) override;
	//zwraca listê informacji o wszystkich statkach na planszy
	std::list<ShipInfo> getShipList() const; //zaimplementowaæ po przeniesieniu listy statków do klas potomnych
	//zwraca informacje o statku le¿¹cym na polu 'point'
	ShipInfo getSquareShip(Point point) const override;
	//usuwa ca³¹ zawartoœæ planszy
	void clear();
};