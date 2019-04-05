#pragma once
#include <vector> //std::vector

class Square;

class Ship {
private:
	const int size;
	std::vector<Square*> location;
public:
	Ship(int _size);
	~Ship();
};