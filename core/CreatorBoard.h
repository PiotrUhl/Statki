#pragma once
#include <memory>
#include "Game.h"

class CreatorBoard {
public:
	std::unique_ptr<Board> makeBoard(Game::playerType playerType);
private:
	std::unique_ptr<Board> makeForHuman();
	std::unique_ptr<Board> makeForAI();
	std::unique_ptr<Board> makeForRemote();
};