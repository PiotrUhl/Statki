#pragma once
#include "Player.h"

class PlayerHuman :	public Player {
public:
	//konstruktor
	PlayerHuman(int _BOARD_SIZE);
	//destruktor
	~PlayerHuman();
	//gracz wykonuje swój ruch (IUserInterface In)
	void move() override;
};

