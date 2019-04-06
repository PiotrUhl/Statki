#ifdef NETMODULE
#pragma once
#include "Player.h"

class PlayerRemote : public Player {
public:
	//konstruktor
	PlayerRemote(int _BOARD_SIZE);
	//destruktor
	~PlayerRemote();
	//gracz wykonuje swój ruch (INetInterface In)
	void move() override;
};
#endif