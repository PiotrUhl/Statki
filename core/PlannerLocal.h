#pragma once
#include "BoardLocal.h"
#include <memory>

class PlannerLocal {
protected:
	BoardLocal& board; //tworzona plansza
public:
	PlannerLocal(BoardLocal&); //konstruktor
	//sprawdza mo�liwo�� po�o�enia statku o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction
	bool checkPlacement(int shipSize, int x, int y, Direction direction);
	//umieszcza statkek o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
	bool place(int shipSize, int x, int y, Direction direction);
	//zwraca obraz tworzonej planszy
	boost::multi_array<unsigned char, 2> getImage();
	//zwraca tworzon� plansz�
	BoardLocal& getBoard() const;
};