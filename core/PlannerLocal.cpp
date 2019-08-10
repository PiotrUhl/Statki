#include "PlannerLocal.h"
#include <stdexcept>      // std::invalid_argument

//konstruktor
PlannerLocal::PlannerLocal(BoardLocal& _board) : board(_board) {}

//sprawdza mo�liwo�� po�o�enia statku o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction
bool PlannerLocal::checkPlacement(int shipSize, int x, int y, Direction direction = Direction::HORIZONTAL) {
	for (int i = 0; i < shipSize; i++) { //dla ka�dego pola na kt�rym ma le�e� statek
		int _x; //wsp�rz�dna x �rodka sprawdzanego kwadratu
		int _y; //wsp�rz�dna y �rodka sprawdzanego kwadratu
		if (direction == Direction::HORIZONTAL) {
			_x = x + i;
			_y = y;
		}
		else if (direction == Direction::VERTICAL) {
			_x = x;
			_y = y + i;
		}
		else
			throw (std::invalid_argument("Incorrect ship direction"));
		if (_x < 0 || _y < 0 || _x >= BOARDSIZE || _y >= BOARDSIZE) //je�li sprawdzane pole le�y poza plansz�
			return false;
		for (int j = -1; j < 2; j++) {
			for (int k = -1; k < 2; k++) {
				if (_x + j < 0 || _y + k < 0 || _x + j >= BOARDSIZE || _y + k >= BOARDSIZE) //je�eli sprawdzane pole le�y poza plansz�, pomi�
					continue;
				if (board[_y + k][_x + j] != nullptr)
					return false;
			}
		}
	}
	return true;
}
//umieszcza statkek o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ; zwraca rezultat
bool PlannerLocal::place(int shipSize, int x, int y, Direction direction) {
	if (checkPlacement(shipSize, x, y, direction) == false)
		return false;
	return board.placeShip(shipSize, x, y, direction);
}

//zwraca obraz tworzonej planszy
boost::multi_array<unsigned char, 2> PlannerLocal::getImage() {
	return board.getImage();
}

//zwraca tworzon� plansz�
BoardLocal& PlannerLocal::getBoard() const {
	return board;
}