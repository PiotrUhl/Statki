#ifdef NETMODULE
#pragma once
#include "Player.h"

class PlayerRemote : public Player {
public:
	//konstruktor
	PlayerRemote(int _BOARDSIZE, Board& _myBoard, Board& _otherBoard);
	//destruktor
	~PlayerRemote();
	//gracz wykonuje sw�j ruch (INetInterface)
	void move() override;
};
#endif