#pragma once
#include <memory> //std::shared_ptr

class Ship;

class Square {
private:
	std::shared_ptr<Ship> ship;
public:
	Square();
	~Square();
};