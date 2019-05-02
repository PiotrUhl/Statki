#pragma once

class Board {
protected:
	enum ShotResult { SUNK, HIT, MISS }; //rezultat strza³u
	const int BOARDSIZE; //rozmiar planszy
public:
	//konstruktor
	Board(int _BOARDSIZE);
	//destruktor
	virtual ~Board();
	//strzela w pole planszy o wspó³rzêdnych (x, y); zwraca rezultat
	virtual ShotResult shot(int x, int y) = 0;
};