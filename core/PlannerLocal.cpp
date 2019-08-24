#include "PlannerLocal.h"
#include <stdexcept>      // std::invalid_argument

//konstruktor
PlannerLocal::PlannerLocal(BoardLocal& _board) : board(_board) {}

//sprawdza mo¿liwoœæ po³o¿enia statku o rozmiarze 'shipSize' w 'point', w kierunku 'direction'
bool PlannerLocal::checkPlacement(int shipSize, Point point, Direction direction = Direction::HORIZONTAL) {
	for (int i = 0; i < shipSize; i++) { //dla ka¿dego pola na którym ma le¿eæ statek
		Point _point; //œrodek sprawdzanego kwadratu
		if (direction == Direction::HORIZONTAL) {
			_point.x = point.x + i;
			_point.y = point.y;
		}
		else if (direction == Direction::VERTICAL) {
			_point.x = point.x;
			_point.y = point.y + i;
		}
		else
			throw (std::invalid_argument("Incorrect ship direction"));
		if (_point.x < 0 || _point.y < 0 || _point.x >= BOARDSIZE || _point.y >= BOARDSIZE) //jeœli sprawdzane pole le¿y poza plansz¹
			return false;
		for (int j = -1; j < 2; j++) {
			for (int k = -1; k < 2; k++) {
				if (_point.x + j < 0 || _point.y + k < 0 || _point.x + j >= BOARDSIZE || _point.y + k >= BOARDSIZE) //je¿eli sprawdzane pole le¿y poza plansz¹, pomiñ
					continue;
				if (board[_point.y + k][_point.x + j] != nullptr)
					return false;
			}
		}
	}
	return true;
}
//umieszcza statkek o rozmiarze 'shipSize' w 'point', w kierunku 'direction'; zwraca rezultat
bool PlannerLocal::place(int shipSize, Point point, Direction direction) {
	if (checkPlacement(shipSize, point, direction) == false)
		return false;
	return board.placeShip(shipSize, point, direction);
}

//usuwa statek le¿¹cy na polu 'point'
bool PlannerLocal::remove(Point point) {
	return board.removeShip(point);
}

//zwraca obraz tworzonej planszy
boost::multi_array<unsigned char, 2> PlannerLocal::getImage() {
	return board.getImage();
}

//zwraca tworzon¹ planszê
BoardLocal& PlannerLocal::getBoard() const {
	return board;
}