#pragma once
#include <memory>
#include "Game.h"
#include "structs.hpp"

class CreatorBoard {
	const int BOARDSIZE;
public:
	CreatorBoard(int _BOARDSIZE, IUserInterface&);
	std::unique_ptr<Board> makeBoard(PlayerType PlayerType);
	IUserInterface& userInterface;
private:
	std::unique_ptr<Board> makeForHuman();
	std::unique_ptr<Board> makeForAI();
	std::unique_ptr<Board> makeForRemote();
};