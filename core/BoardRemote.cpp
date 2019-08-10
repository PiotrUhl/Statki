#ifdef NETMODULE
#include "BoardRemote.h"

//konstruktor
BoardRemote::BoardRemote() : Board() {}

//destruktor
BoardRemote::~BoardRemote() {}

//strzela w pole 'point'; zwraca rezultat (INetInterface)
ShotResult BoardRemote::shot(Point point) {
	return ShotResult::MISS; //temp
}
#endif