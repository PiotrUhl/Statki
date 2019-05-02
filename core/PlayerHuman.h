#pragma once
#include "Player.h"
#include <stdexcept>      // std::out_of_range; std::logic_error
class PlayerHuman :	public Player {
public:
	//konstruktor
	PlayerHuman(int _BOARDSIZE, Board& _myBoard, Board& _otherBoard);
	//destruktor
	~PlayerHuman();
	//gracz wykonuje swój ruch (IUserInterface In)
	void move() override;
};

