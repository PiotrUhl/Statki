#include "CreatorBoard.h"
#include "Board.h"
#include "BoardLocal.h"
#include "BoardRemote.h"
#include "PlannerLocal.h"
#include "PlannerLocalAI.h"
#include "IUserInterface.h"
#include "UserDllInterface.h"


CreatorBoard::CreatorBoard(int _BOARDSIZE, IUserInterface& _userInterface) : BOARDSIZE(_BOARDSIZE), userInterface(_userInterface){}

std::unique_ptr<Board> CreatorBoard::makeBoard(PlayerType PlayerType) {
	switch (PlayerType) {
	case PlayerType::HUMAN:
		return makeForHuman();
	case PlayerType::AI:
		return makeForAI();
	case PlayerType::REMOTE:
		return makeForRemote();
	}
	return nullptr;
}

std::unique_ptr<Board> CreatorBoard::makeForHuman() {
	PlannerLocal planner(BOARDSIZE, userInterface);
	userInterface.makeBoard(&planner);
	return std::make_unique<BoardLocal>(planner.getBoard());
}

std::unique_ptr<Board> CreatorBoard::makeForAI() {
	PlannerLocalAI planner(BOARDSIZE, userInterface);
	return std::make_unique<BoardLocal>(planner.makeBoard());
}

std::unique_ptr<Board> CreatorBoard::makeForRemote() {
	//todo: inicjalizacja planszy zdalnej
	return std::make_unique<BoardRemote>(BOARDSIZE, userInterface);
}