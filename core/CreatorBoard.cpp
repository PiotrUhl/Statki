#include "CreatorBoard.h"

CreatorBoard::CreatorBoard(int _BOARDSIZE) : BOARDSIZE(_BOARDSIZE) {}

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
	//todo: tworzenie planszy z interfejsu
	return std::make_unique<BoardLocal>(BOARDSIZE);
}

std::unique_ptr<Board> CreatorBoard::makeForAI() {
	//todo: tworzenie planszy z algorytmu
	return std::make_unique<BoardLocal>(BOARDSIZE);
}

std::unique_ptr<Board> CreatorBoard::makeForRemote() {
	//todo: inicjalizacja planszy zdalnej
	return std::make_unique<BoardRemote>(BOARDSIZE);
}