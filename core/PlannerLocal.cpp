#include "PlannerLocal.h"

//konstruktor
PlannerLocal::PlannerLocal(int _BOARDSIZE) : BOARDSIZE(_BOARDSIZE), board(_BOARDSIZE) {}
//destruktor
PlannerLocal::~PlannerLocal() {}

#include <stdexcept>      // std::invalid_argument

//sprawdza mo¿liwoœæ po³o¿enia statku o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
bool PlannerLocal::checkPlacement(int shipSize, int x, int y, char direction = 'H') {
	for (int i = 0; i < shipSize; i++) { //dla ka¿dego pola na którym ma le¿eæ statek
		int _x; //wspó³rzêdna x œrodka sprawdzanego kwadratu
		int _y; //wspó³rzêdna y œrodka sprawdzanego kwadratu
		if (direction == 'H') {
			_x = x + i;
			_y = y;
		}
		else if (direction == 'V') {
			_x = x;
			_y = y + i;
		}
		else
			throw (std::invalid_argument("Incorrect ship direction"));
		for (int j = -1; j < 2; j++) {
			for (int k = -1; k < 2; k++) {
				if (_x + j < 0 || _y + k < 0 || _x + j >= BOARDSIZE || _y + k >= BOARDSIZE) //je¿eli sprawdzane pole le¿y poza plansz¹, pomiñ
					continue;
				if (board[_x + j][_y + k] != nullptr)
					return false;
			}
		}
	}
	return true;
}