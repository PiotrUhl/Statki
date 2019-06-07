#pragma once
#include <memory>
#include "Game.h"

class CreatorBoard {
	const int BOARDSIZE;
public:
	CreatorBoard(int _BOARDSIZE);
	std::unique_ptr<Board> makeBoard(Game::PlayerType PlayerType);
private:
	std::unique_ptr<Board> makeForHuman();
	std::unique_ptr<Board> makeForAI();
	std::unique_ptr<Board> makeForRemote();
};