#include "CreatorBoard.h"

std::unique_ptr<Board> CreatorBoard::makeBoard(Game::playerType playerType) {
	switch (playerType) {
	case Game::playerType::HUMAN:
		return makeForHuman();
	case Game::playerType::AI:
		return makeForAI();
	case Game::playerType::REMOTE:
		return makeForRemote();
	}
	return nullptr;
}

std::unique_ptr<Board> CreatorBoard::makeForHuman() {
	return nullptr;
}

std::unique_ptr<Board> CreatorBoard::makeForAI() {
	return nullptr;
}

std::unique_ptr<Board> CreatorBoard::makeForRemote() {
	return nullptr;
}