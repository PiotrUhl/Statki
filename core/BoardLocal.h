#pragma once
#include "Board.h"
#include "Square.h"
#include <vector>

class BoardLocal : public Board {
private:
	std::vector<std::vector<Square>> board;
public:
	BoardLocal(int _BOARD_SIZE);
	~BoardLocal();
};