#pragma once
#include "PlannerLocal.h"
#include <bitset>

class PlannerLocalAI : private PlannerLocal {
	static bool randomInitialized; //czy zainicjalizowano generator liczb losowych
private:
	enum class ShipPlacement {H2 = 0, V2, H3, V3, H4, V4, H5, V5};
	boost::multi_array<std::bitset<8>, 2> placeableMap; //mapa pami�taj�ca gdzie mo�na postawi� statek o danym rozmiarze w danym kierunku
	int placeableSquares[8]; //ilo�� p�l w kt�rych mo�na postawi� statek o danym rozmiarze w danym kierunku
public:
	PlannerLocalAI(BoardLocal&);
	//tworzy plansz� za pomoc� algorytmu
	void makeBoard();
	//zwraca tworzon� plansz�
	BoardLocal& getBoard() const;
private:
	void initializeplaceableMap(); //inicjalizuje placeable warto�ciami domy�lnymi
	bool placeShip(int size); //umieszcza na planszy statek o rozmiarze size
	void resetBoard(); //zaczyna tworzenie planszy od nowa
	int randomNumber(int b); //losuje losow� liczb� naturaln� z zakresu <1, b>
	Point convert(int r, ShipPlacement sp); //konwertuje liczb� naturaln� "r" na punkt dla danego u�o�enia statku "sp"
	ShipPlacement encode(int size, Direction direction); //konwertuje rozmiar i kierunek na odpowiedni ShipPlacement
	void updatePlaceableMap(int size, Direction direction, Point point); //aktualizuje tablic� placeableMap po postawieniu statku
};