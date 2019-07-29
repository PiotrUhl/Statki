#include "CreatorBoard.h"
#include "Board.h"
#include "BoardLocal.h"
#include "BoardRemote.h"
#include "PlannerLocal.h"
#include "PlannerLocalAI.h"
#include "IUserInterface.h"
#include "UserDllInterface.h"


CreatorBoard::CreatorBoard(IUserInterface& _userInterface) : userInterface(_userInterface){}

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
	PlannerLocal planner;
	userInterface.makeBoard(&planner);
	return std::make_unique<BoardLocal>(planner.getBoard());
}

std::unique_ptr<Board> CreatorBoard::makeForAI() {
	PlannerLocalAI planner;
	return std::make_unique<BoardLocal>(planner.makeBoard());
}

std::unique_ptr<Board> CreatorBoard::makeForRemote() {
#ifdef NETMODULE
	//toadd: inicjalizacja planszy zdalnej
	return std::make_unique<BoardRemote>();
#else
	return nullptr;
#endif
}