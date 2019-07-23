#ifdef NETMODULE
#include "BoardRemote.h"

//konstruktor
BoardRemote::BoardRemote(int _BOARDSIZE) : Board(_BOARDSIZE) {}

//destruktor
BoardRemote::~BoardRemote() {}

//strzela w pole planszy o wspó³rzêdnych (x, y); zwraca rezultat (INetInterface)
ShotResult BoardRemote::shot(int x, int y) {
	return ShotResult::MISS; //temp
}
#endif