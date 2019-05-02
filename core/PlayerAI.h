#pragma once
#include "Player.h"

class PlayerAI : public Player {
public:
	//konstruktor
	PlayerAI(int _BOARDSIZE, Board& _myBoard, Board& _otherBoard);
	//destruktor
	~PlayerAI();
	//gracz wykonuje sw�j ruch
	void move() override;
};
