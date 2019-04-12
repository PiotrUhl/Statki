#pragma once
#include "Player.h"
#include <stdexcept>      // std::out_of_range; std::logic_error
class PlayerHuman :	public Player {
public:
	//konstruktor
	PlayerHuman(int _BOARD_SIZE);
	//destruktor
	~PlayerHuman();
	//gracz wykonuje swój ruch (IUserInterface In)
	void move() override;
};

