#pragma once
#include "Board.h"
#include "Square.h"
#include <vector>

class BoardLocal : public Board {
private:
	std::vector<std::vector<Square>> board; //plansza
public:
	//konstruktor
	BoardLocal(int _BOARD_SIZE);
	//destruktor
	~BoardLocal();
	//strzela w pole planszy o wspó³rzêdnych (x, y); zwraca rezultat
	Board::ShotResult shot(int x, int y) override;
};