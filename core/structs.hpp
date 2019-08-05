#pragma once

enum class PlayerType : char { NONE = 0, HUMAN, AI, REMOTE };

enum class ShotResult : char { NONE = 0, MISS, HIT, SUNK };

enum class MsgType : char { NONE = 0, INFO, WARNING, ERROR }; //typ wiadomoœci dla metody IUserInterface::msg()

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