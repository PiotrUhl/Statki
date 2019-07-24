#ifdef NETMODULE
#include "PlayerRemote.h"

//konstruktor
PlayerRemote::PlayerRemote(Board& _myBoard, Board& _otherBoard) : Player(_myBoard, _otherBoard) {}

//destruktor
PlayerRemote::~PlayerRemote() {}

//gracz wykonuje swój ruch (INetInterface)
void PlayerRemote::move() {}
#endif