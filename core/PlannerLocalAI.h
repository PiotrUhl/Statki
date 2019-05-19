#pragma once
#include "PlannerLocal.h"
#include <bitset>

class PlannerLocalAI : private PlannerLocal {
private:
	enum class ShipPlacement {H2 = 0, V2, H3, V3, H4, V4, H5, V5};
	std::vector<std::vector<std::bitset<8>>> placeableMap; //mapa pamiêtaj¹ca gdzie mo¿na postawiæ statek o danym rozmiarze w danym kierunku
	int placeableSquares[8]; //iloœæ pól w których mo¿na postawiæ statek o danym rozmiarze w danym kierunku
public:
	PlannerLocalAI(int _BOARDSIZE);
	//tworzy za pomoc¹ algorytmu i zwraca planszê
	BoardLocal makeBoard();
private:
	void initializeplaceableMap(); //inicjalizuje placeable wartoœciami domyœlnymi
	bool place5(); //umieszcza na planszy statek o rozmiarze 5
	bool place4(); //umieszcza na planszy statek o rozmiarze 4
	bool place3(); //umieszcza na planszy statek o rozmiarze 3
	bool place2(); //umieszcza na planszy statek o rozmiarze 2
	void resetBoard(); //zaczyna tworzenie planszy od nowa
};

