#ifdef NETMODULE
#include "BoardRemote.h"

//konstruktor
BoardRemote::BoardRemote(int _BOARD_SIZE) : Board(_BOARD_SIZE) {}

//destruktor
BoardRemote::~BoardRemote() {}

//strzela w pole planszy o wspó³rzêdnych (x, y); zwraca rezultat (INetInterface)
Board::ShotResult BoardRemote::shot(int x, int y) {
	return ShotResult::MISS;
}
#endif