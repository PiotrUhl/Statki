#pragma once
#include "Board.h"
#include "Square.h"
#include "structs.hpp"
#include <array>

class BoardLocal : public Board {
private:
	std::array<std::array<Square, BOARDSIZE>, BOARDSIZE> board; //plansza
public:
	//konstruktor
	BoardLocal();
	//destruktor
	~BoardLocal();
	//przeci��ony operator []
	std::array<Square, BOARDSIZE>& operator[](int);
	//umieszcza statkek o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
	bool placeShip(int shipSize, int x, int y, char direction);
	//usuwa statkek z pola ("x", "y")
	bool removeShip(int x, int y);
	//zwraca obraz planszy
	std::unique_ptr<std::unique_ptr<char[]>[]> getImage();
	//strzela w pole planszy o wsp�rz�dnych (x, y); zwraca rezultat
	ShotResult shot(int x, int y) override;
	//usuwa ca�� zawarto�� planszy
	void clear();
private:
	//zwraca obraz pola ("x", "y")
	char fillImageSquare(int x, int y);
	//okre�la kierunek statku le��cego na polu  ("x", "y")
	char findDirection(int x, int y);
};