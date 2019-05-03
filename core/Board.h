#pragma once

class Board {
protected:
	enum ShotResult { SUNK, HIT, MISS }; //rezultat strza³u
	const int BOARDSIZE; //rozmiar planszy
	int unsunkShips; //liczba niezatopnionych statków
public:
	//konstruktor
	Board(int _BOARDSIZE);
	//destruktor
	virtual ~Board();
	//zwraca wartoœæ pola unsunkShips
	bool getUnsunkShips();
	//strzela w pole planszy o wspó³rzêdnych (x, y); zwraca rezultat
	virtual ShotResult shot(int x, int y) = 0;
};
//todo: dodaæ id