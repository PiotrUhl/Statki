#pragma once
#include "PlannerLocal.h"
#include <bitset>

class PlannerLocalAI : private PlannerLocal {
private:
	enum class ShipPlacement {H1 = 0, V1, H2, V2, H3, V3, H4, V4};
	std::vector<std::vector<std::bitset<8>>> placeableMap; //mapa pami�taj�ca gdzie mo�na postawi� statek o danym rozmiarze w danym kierunku
	int placeableSquares[8]; //ilo�� p�l w kt�rych mo�na postawi� statek o danym rozmiarze w danym kierunku
public:
	PlannerLocalAI(int _BOARDSIZE);
	//tworzy za pomoc� algorytmu i zwraca plansz�
	BoardLocal makeBoard();
private:
	void initializeplaceableMap(); //inicjalizuje placeable warto�ciami domy�lnymi
	bool place4(); //umieszcza na planszy statek o rozmiarze 4
	bool place3(); //umieszcza na planszy statek o rozmiarze 3
	bool place2(); //umieszcza na planszy statek o rozmiarze 2
	bool place1(); //umieszcza na planszy statek o rozmiarze 1
	void resetBoard(); //zaczyna tworzenie planszy od nowa
};

