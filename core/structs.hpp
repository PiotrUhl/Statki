#pragma once

enum class PlayerType { NONE = 0, HUMAN, AI, REMOTE };

enum class ShotResult { NONE = 0, MISS, HIT, SUNK };

struct Point {
	int x;
	int y;
};

struct InitData {
	PlayerType player1type;
	PlayerType player2type;
};

struct ShipInfo {
	int size;
	int x;
	int y;
	char direction;
	bool sunk;
};