#include "LocalBoard.h"

LocalBoard::LocalBoard(int _BOARD_SIZE) : Board(_BOARD_SIZE), board(BOARD_SIZE, std::vector<Square>(BOARD_SIZE)) {}

LocalBoard::~LocalBoard() {}