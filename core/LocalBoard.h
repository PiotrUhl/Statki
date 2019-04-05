#pragma once
#include "Board.h"
#include "Square.h"
#include <vector>

class LocalBoard : public Board {
private:
	std::vector<std::vector<Square>> board;
public:
	LocalBoard(int _BOARD_SIZE);
	~LocalBoard();
};