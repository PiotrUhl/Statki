#include "BoardLocal.h"

//konstruktor
BoardLocal::BoardLocal(int _BOARDSIZE) : Board(_BOARDSIZE), board(BOARDSIZE, std::vector<Square>(BOARDSIZE)) {}

//destruktor
BoardLocal::~BoardLocal() {}

//przeci��ony operator []
std::vector<Square>& BoardLocal::operator [](int i) {
	return board[i];
}

//umieszcza statkek o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
bool BoardLocal::placeShip(int shipSize, int x, int y, char direction) {
	if ((x < 0) || (y < 0) || (direction = 'H' && x + shipSize >= BOARDSIZE) || (direction = 'V' && y + shipSize >= BOARDSIZE)) //pr�ba umieszczenia statku poza plansz�
		return false;
	std::shared_ptr<Ship> newShip = std::make_shared<Ship>(shipSize);
	if (direction == 'H')
		for (int i = 0; i < shipSize; i++) {
			board[y][x + i].set(newShip);
		}
	else if (direction == 'V')
		for (int i = 0; i < shipSize; i++) {
			board[y + i][x].set(newShip);
		}
	else
		throw (std::invalid_argument("Incorrect ship direction"));
	return true;
}

std::shared_ptr<char> BoardLocal::getImage() {
	return nullptr;
}

//strzela w pole planszy o wsp�rz�dnych (x, y); zwraca rezultat
Board::ShotResult BoardLocal::shot(int x, int y) {
	return static_cast<Board::ShotResult>(board.at(x).at(y).shot()); //strzel w dane pole
}