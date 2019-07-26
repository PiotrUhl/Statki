#pragma once
#include "PlannerLocal.h"
#include "point.hpp"
#include <bitset>

class PlannerLocalAI : private PlannerLocal {
private:
	enum class ShipPlacement {H2 = 0, V2, H3, V3, H4, V4, H5, V5};
	boost::multi_array<std::bitset<8>, 2> placeableMap; //mapa pamiêtaj¹ca gdzie mo¿na postawiæ statek o danym rozmiarze w danym kierunku
	int placeableSquares[8]; //iloœæ pól w których mo¿na postawiæ statek o danym rozmiarze w danym kierunku
public:
	PlannerLocalAI();
	//tworzy za pomoc¹ algorytmu i zwraca planszê
	BoardLocal makeBoard();
private:
	void initializeplaceableMap(); //inicjalizuje placeable wartoœciami domyœlnymi
	bool placeShip(int size); //umieszcza na planszy statek o rozmiarze size
	void resetBoard(); //zaczyna tworzenie planszy od nowa
	int randomNumber(int b); //losuje losow¹ liczbê naturaln¹ z zakresu <1, b>
	Point convert(int r, ShipPlacement sp); //konwertuje liczbê naturaln¹ "r" na punkt dla danego u³o¿enia statku "sp"
	ShipPlacement encode(int size, char direction); //konwertuje rozmiar i kierunek na odpowiedni ShipPlacement
	void updatePlaceableMap(int size, char direction, int x, int y); //aktualizuje tablicê placeableMap po postawieniu statku
};