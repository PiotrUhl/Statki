#pragma once

class Board {
protected:
	const int BOARD_SIZE;
public:
	Board(int _BOARD_SIZE);
	virtual ~Board();
};