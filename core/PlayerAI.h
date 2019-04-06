#pragma once
#include "Player.h"

class PlayerAI : public Player {
public:
	//konstruktor
	PlayerAI(int _BOARD_SIZE);
	//destruktor
	~PlayerAI();
	//gracz wykonuje swój ruch
	void move() override;
};
