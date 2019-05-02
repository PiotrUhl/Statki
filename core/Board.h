#pragma once

class Board {
protected:
	enum ShotResult { SUNK, HIT, MISS }; //rezultat strza�u
	const int BOARDSIZE; //rozmiar planszy
public:
	//konstruktor
	Board(int _BOARDSIZE);
	//destruktor
	virtual ~Board();
	//strzela w pole planszy o wsp�rz�dnych (x, y); zwraca rezultat
	virtual ShotResult shot(int x, int y) = 0;
};