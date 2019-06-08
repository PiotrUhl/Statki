#pragma once
enum class PlayerType;

struct InitData {
	int boardsize;
	PlayerType player1type;
	PlayerType player2type;
};

struct ShipInfo {
	int size;
	int x;
	int y;
	char direction;
	bool sunk;
	ShipInfo() = default;
	ShipInfo(int _size, int _x, int _y, char _direction, bool _sunk = 0) : size(_size), x(_x), y(_y), direction(_direction), sunk(_sunk) {}
};