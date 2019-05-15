#include "CreatorBoard.h"

std::unique_ptr<Board> CreatorBoard::makeBoard(Game::playerType playerType) {
	switch (playerType) {
	case Game::playerType::HUMAN:
		return nullptr;
	case Game::playerType::AI:
		return nullptr;
	case Game::playerType::REMOTE:
		return nullptr;
	}
	return nullptr;
}