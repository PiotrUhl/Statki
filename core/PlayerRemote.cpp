#ifdef NETMODULE
#include "PlayerRemote.h"

//konstruktor
PlayerRemote::PlayerRemote(int _BOARD_SIZE) : Player(_BOARD_SIZE) {}

//destruktor
PlayerRemote::~PlayerRemote() {}

//gracz wykonuje sw�j ruch (INetInterface In)
void PlayerRemote::move() {}
#endif