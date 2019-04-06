#include "BoardLocal.h"

BoardLocal::BoardLocal(int _BOARD_SIZE) : Board(_BOARD_SIZE), board(BOARD_SIZE, std::vector<Square>(BOARD_SIZE)) {}

BoardLocal::~BoardLocal() {}