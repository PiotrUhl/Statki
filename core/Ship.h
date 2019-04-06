#pragma once
#include <vector> //std::vector

class Square;

class Ship {
private:
	const int size; //rozmiar statku (1..4)
	std::vector<Square*> location; //po�o�enie statku (pola na kt�rych le�y)
public:
	//konstruktor
	Ship(int _size);
	//destruktor
	~Ship();
	//trafiono w statek; zwraca czy zatopiono statek
	bool hit();
};