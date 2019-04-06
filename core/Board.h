#pragma once

class Board {
protected:
	enum class ShotResult {SUNK, HIT, MISS};
	const int BOARD_SIZE; //rozmiar planszy
public:
	//konstruktor
	Board(int _BOARD_SIZE);
	//destruktor
	virtual ~Board();
	//strzela w pole planszy o wspó³rzêdnych (x, y); zwraca rezultat
	virtual ShotResult shot(int x, int y);
};