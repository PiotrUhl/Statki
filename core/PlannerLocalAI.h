#pragma once
#include "PlannerLocal.h"
#include <bitset>

class PlannerLocalAI : private PlannerLocal {
private:
	enum class ShipPlacement {H2 = 0, V2, H3, V3, H4, V4, H5, V5};
	std::vector<std::vector<std::bitset<8>>> placeableMap; //mapa pami�taj�ca gdzie mo�na postawi� statek o danym rozmiarze w danym kierunku
	int placeableSquares[8]; //ilo�� p�l w kt�rych mo�na postawi� statek o danym rozmiarze w danym kierunku
	struct Point {
		int x; int y;
		Point(int _x, int _y) : x(_x), y(_y) {}
	}; //punkt 2D
public:
	PlannerLocalAI(int _BOARDSIZE, IUserInterface&);
	//tworzy za pomoc� algorytmu i zwraca plansz�
	BoardLocal makeBoard();
private:
	void initializeplaceableMap(); //inicjalizuje placeable warto�ciami domy�lnymi
	bool placeShip(int size); //umieszcza na planszy statek o rozmiarze size
	void resetBoard(); //zaczyna tworzenie planszy od nowa
	int randomNumber(int b); //losuje losow� liczb� naturaln� z zakresu <1, b>
	Point convert(int r, ShipPlacement sp); //konwertuje liczb� naturaln� "r" na punkt dla danego u�o�enia statku "sp"
	ShipPlacement encode(int size, char direction); //konwertuje rozmiar i kierunek na odpowiedni ShipPlacement
	void updatePlaceableMap(int size, char direction, int x, int y); //aktualizuje tablic� placeableMap po postawieniu statku
};