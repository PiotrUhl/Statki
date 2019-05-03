#pragma once

class Board {
protected:
	enum ShotResult { SUNK, HIT, MISS }; //rezultat strza�u
	const int BOARDSIZE; //rozmiar planszy
	int unsunkShips; //liczba niezatopnionych statk�w
public:
	//konstruktor
	Board(int _BOARDSIZE);
	//destruktor
	virtual ~Board();
	//zwraca warto�� pola unsunkShips
	bool getUnsunkShips();
	//strzela w pole planszy o wsp�rz�dnych (x, y); zwraca rezultat
	virtual ShotResult shot(int x, int y) = 0;
};
//todo: doda� id