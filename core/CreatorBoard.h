#pragma once
#include <memory>
#include "Game.h"

class CreatorBoard {
public:
	std::unique_ptr<Board> makeBoard(Game::playerType playerType);
};

