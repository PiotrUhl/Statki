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
	std::unique_ptr<BoardLocal> board = std::make_unique<BoardLocal>();
	userInterface.makeBoard(*board);
	return board;
}

std::unique_ptr<Board> CreatorBoard::makeForAI() {
	std::unique_ptr<BoardLocal> board = std::make_unique<BoardLocal>();
	PlannerLocalAI planner(*board);
	planner.makeBoard();
	return board;
}

std::unique_ptr<Board> CreatorBoard::makeForRemote() {
#ifdef NETMODULE
	//toadd: inicjalizacja planszy zdalnej
	return std::make_unique<BoardRemote>();
#else
	return nullptr;
#endif
}