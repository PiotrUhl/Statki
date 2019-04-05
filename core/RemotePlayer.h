#ifdef NETMODULE
#pragma once
#include "Player.h"

class RemotePlayer : public Player {
public:
	RemotePlayer(int _BOARD_SIZE);
	~RemotePlayer();
};
#endif