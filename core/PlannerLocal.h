#pragma once
#include "BoardLocal.h"
#include <memory>

class PlannerLocal {
protected:
	BoardLocal& board; //tworzona plansza
public:
	PlannerLocal(BoardLocal&); //konstruktor
	//sprawdza mo¿liwoœæ po³o¿enia statku o rozmiarze 'shipSize' w 'point', w kierunku 'direction'
	bool checkPlacement(int shipSize, Point point, Direction direction);
	//umieszcza statkek o rozmiarze 'shipSize' w 'point', w kierunku 'direction'; zwraca rezultat
	bool place(int shipSize, Point point, Direction direction);
	//usuwa statek le¿¹cy na polu 'point'
	bool remove(Point point);
	//zwraca obraz tworzonej planszy
	boost::multi_array<unsigned char, 2> getImage();
	//zwraca tworzon¹ planszê
	BoardLocal& getBoard() const;
};