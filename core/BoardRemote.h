#ifdef NETMODULE
#pragma once
#include "Board.h"

class BoardRemote : public Board {
public:
	//konstruktor
	BoardRemote();
	//destruktor
	~BoardRemote();
	//strzela w pole planszy o wsp�rz�dnych (x, y); zwraca rezultat (INetInterface)
	ShotResult shot(int x, int y) override;
};
#endif