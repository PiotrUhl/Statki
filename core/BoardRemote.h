#ifdef NETMODULE
#pragma once
#include "Board.h"

class BoardRemote : public Board {
public:
	//konstruktor
	BoardRemote(int _BOARD_SIZE);
	//destruktor
	~BoardRemote();
	//strzela w pole planszy o wspó³rzêdnych (x, y); zwraca rezultat (INetInterface)
	ShotResult shot(int x, int y) override;
};
#endif