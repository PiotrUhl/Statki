#pragma once
#include "Board.h"
#include <memory> //std::shared_ptr

class Player {
private:
	int BOARD_SIZE;
	Board myBoard;
	Board* otherBoard;
public:
	Player(int _BOARD_SIZE);
	virtual ~Player();
};