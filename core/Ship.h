#pragma once
#include <vector> //std::vector

class Square;

class Ship {
private:
	const int size; //rozmiar statku (2..5)
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
	//zwraca size
	int getSize() const;
	//zwraca sunk
	bool getSunk() const;
private:
	//sprawdza czy statek jest zatopiony
	bool checkSunk();
};