#ifdef NETMODULE
#pragma once
#include "Player.h"

class PlayerRemote : public Player {
public:
	//konstruktor
	PlayerRemote(Board& _myBoard, Board& _otherBoard);
	//destruktor
	~PlayerRemote();
	//gracz wykonuje swój ruch (INetInterface)
	void move() override;
};
#endif