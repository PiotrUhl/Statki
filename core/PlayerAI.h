#pragma once
#include "Player.h"

class PlayerAI : public Player {
public:
	//konstruktor
	PlayerAI(int _BOARD_SIZE);
	//destruktor
	~PlayerAI();
	//gracz wykonuje sw�j ruch
	void move() override;
};
