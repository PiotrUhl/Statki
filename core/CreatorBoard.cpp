#include "CreatorBoard.h"
#include "Board.h"
#include "BoardLocal.h"
#include "BoardRemote.h"
#include "PlannerLocal.h"
#include "IUserInterface.h"
#include "UserDllInterface.h"


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
	PlannerLocal planner(BOARDSIZE);
	IUserInterface& userInterface = UserDllInterface::getInstance();
	userInterface.makeBoard(&planner);
	return std::make_unique<BoardLocal>(planner.getBoard());
}

std::unique_ptr<Board> CreatorBoard::makeForAI() {
	PlannerLocal planner(BOARDSIZE);
	//todo: tworzenie planszy z algorytmu
	return std::make_unique<BoardLocal>(planner.getBoard());
}

std::unique_ptr<Board> CreatorBoard::makeForRemote() {
	//todo: inicjalizacja planszy zdalnej
	return std::make_unique<BoardRemote>(BOARDSIZE);
}