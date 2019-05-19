#pragma once
#include <vector> //std::vector

class Square;

class Ship {
private:
	const int size; //rozmiar statku (1..4)
	std::vector<Square*> location; //po�o�enie statku (pola na kt�rych le�y)
	int damage; //ilo�� trafie� przyj�tych przez statek
	bool sunk; //czy statek jest zatopiony
public:
	//konstruktor
	Ship(int _size);
	//destruktor
	~Ship();
	//trafiono w statek; zwraca czy zatopiono statek
	bool hit();
	//usuwa statek z planszy
	void remove();
private:
	//sprawdza czy statek jest zatopiony
	bool checkSunk();
};