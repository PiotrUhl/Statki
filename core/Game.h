#pragma once
#include "UserInterface.h"
#include "Player.h"
#include <memory> //std::unique_ptr

class Player;

class Game {
private:
	enum class playerType { NONE, HUMAN, AI, REMOTE };
	playerType player1Type;
	playerType player2Type;
	std::unique_ptr<Player> player1;
	std::unique_ptr<Player> player2;
public:
	Game();
	~Game();
	void run();
};