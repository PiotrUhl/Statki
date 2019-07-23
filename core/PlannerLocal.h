#pragma once
#include "BoardLocal.h"
#include <memory>

class PlannerLocal {
protected:
	const int BOARDSIZE; //rozmiar planszy
	BoardLocal board; //tworzona plansza
public:
	PlannerLocal(int _BOARDSIZE); //konstruktor
	//sprawdza mo�liwo�� po�o�enia statku o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
	bool checkPlacement(int shipSize, int x, int y, char direction);
	//umieszcza statkek o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
	bool place(int shipSize, int x, int y, char direction);
	//zwraca obraz tworzonej planszy
	std::unique_ptr<std::unique_ptr<char[]>[]> getImage();
	//zwraca tworzon� plansz� - niszczy obiekt
	BoardLocal getBoard();
};