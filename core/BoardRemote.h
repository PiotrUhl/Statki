#ifdef NETMODULE
#pragma once
#include "Board.h"

class BoardRemote : public Board {
public:
	//konstruktor
	BoardRemote();
	//destruktor
	~BoardRemote();
	//strzela w pole 'point'; zwraca rezultat (INetInterface)
	ShotResult shot(Point point) override;
};
#endif