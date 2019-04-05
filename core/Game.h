#pragma once
#include "UserInterface.h"
#include <memory> //std::unique_ptr

class Player;

class Game {
private:
	std::unique_ptr<Player> player1;
	std::unique_ptr<Player> player2;
public:
	Game();
	~Game();
	static void run();
};