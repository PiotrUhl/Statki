#include "BoardLocal.h"

//konstruktor
BoardLocal::BoardLocal(int _BOARD_SIZE) : Board(_BOARD_SIZE), board(BOARD_SIZE, std::vector<Square>(BOARD_SIZE)) {}

//destruktor
BoardLocal::~BoardLocal() {}

//strzela w pole planszy o wsp�rz�dnych (x, y); zwraca rezultat
Board::ShotResult BoardLocal::shot(int x, int y) {
	return static_cast<Board::ShotResult>(board.at(x).at(y).shot()); //strzel w dane pole
}