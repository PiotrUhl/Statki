#ifdef NETMODULE
#include "PlayerRemote.h"

//konstruktor
PlayerRemote::PlayerRemote(int _BOARDSIZE, Board& _myBoard, Board& _otherBoard) : Player(_BOARDSIZE, _myBoard, _otherBoard) {}

//destruktor
PlayerRemote::~PlayerRemote() {}

//gracz wykonuje swój ruch (INetInterface)
void PlayerRemote::move() {}
#endif