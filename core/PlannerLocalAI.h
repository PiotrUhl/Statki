#pragma once
#include "PlannerLocal.h"
#include <bitset>

class PlannerLocalAI : private PlannerLocal {
private:
	std::vector<std::vector<std::bitset<8>>> placeable;
public:
	PlannerLocalAI(int _BOARDSIZE);
	//tworzy za pomoc� algorytmu i zwraca plansz�
	BoardLocal makeBoard();
private:
	void initializeplaceable(); //inicjalizuje placeable warto�ciami domy�lnymi
	bool place4(); //umieszcza na planszy statek o rozmiarze 4
	bool place3(); //umieszcza na planszy statek o rozmiarze 3
	bool place2(); //umieszcza na planszy statek o rozmiarze 2
	bool place1(); //umieszcza na planszy statek o rozmiarze 1
	void resetBoard(); //zaczyna tworzenie planszy od nowa
};

