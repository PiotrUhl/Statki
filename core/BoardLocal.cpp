#include "BoardLocal.h"

//konstruktor
BoardLocal::BoardLocal(int _BOARDSIZE) : Board(_BOARDSIZE), board(BOARDSIZE, std::vector<Square>(BOARDSIZE)) {}

//destruktor
BoardLocal::~BoardLocal() {}

//przeci¹¿ony operator []
std::vector<Square>& BoardLocal::operator [](int i) {
	return board[i];
}

#include "Ship.h"

//umieszcza statkek o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
bool BoardLocal::placeShip(int shipSize, int x, int y, char direction) {
	if ((x < 0) || (y < 0) || (direction == 'H' && x + shipSize - 1 >= BOARDSIZE) || (direction == 'V' && y + shipSize - 1 >= BOARDSIZE)) //próba umieszczenia statku poza plansz¹
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
	unsunkShips++;
	list.push_back(ShipInfo(shipSize, x, y, direction, false));
	return true;
}

//usuwa statkek z pola (x, y)
bool BoardLocal::removeShip(int x, int y) {
	list.remove_if([x, y](ShipInfo v) { //usuñ statek z listy
		if (v.x == x && v.y == y)
			return true;
		else
			return false;
	});
	return board[y][x].removeShip();
}

//zwraca obraz planszy
std::unique_ptr<std::unique_ptr<char[]>[]> BoardLocal::getImage() {
	std::unique_ptr<std::unique_ptr<char[]>[]> image = std::make_unique<std::unique_ptr<char[]>[]>(BOARDSIZE);
	for (int i = 0; i < BOARDSIZE; i++) {
		image[i] = std::make_unique<char[]>(BOARDSIZE);
	}
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			image[i][j] = fillImageSquare(j, i);
		}
	}
	return image;
}

//zwraca obraz pola ("x", "y")
char BoardLocal::fillImageSquare(int x, int y) {
	if (board[x][y] == nullptr) { //pole puste
		if (board[x][y].getShooted() == true) { //pole puste i postrzelone
			return 1;
		}
		else { //pole puste i niepostrzelone
			return 0;
		}
	}
	else { //pole niepuste
		char ret = 0;
		if (findDirection(x, y) == 'H') { //statek poziomo
			ret += 10;
		}
		else { //statek pionowo
			ret += 20;
		}
		if (board[x][y].getShooted() == true) { //statek postrzelony
			if (board[x][y].getSunk() == true) { //statek zatopiony
				ret += 200;
			}
			else { //statek p³onie
				ret += 100;
			}
		}
		ret += board[x][y].getSize();
		return ret;
	}
	return 255; //b³¹d
}

//okreœla kierunek statku le¿¹cego na polu  ("x", "y")
char BoardLocal::findDirection(int x, int y) {
	if (x > 0 && board[x - 1][y] != nullptr)
		return 'H';
	if (x < BOARDSIZE - 1 && board[x + 1][y] != nullptr)
		return 'H';
	if (y > 0 && board[x][y - 1] != nullptr)
		return 'V';
	if (y < BOARDSIZE - 1 && board[x][y + 1] != nullptr)
		return 'V';
	return 255; //b³ad
}

//strzela w pole planszy o wspó³rzêdnych (x, y); zwraca rezultat
ShotResult BoardLocal::shot(int x, int y) {
	shotMap[y][x] = board.at(x).at(y).shot(); //strzel w dane pole
	if (shotMap[y][x] == ShotResult::SUNK)
		unsunkShips--;
	return shotMap[y][x];
}

//usuwa ca³¹ zawartoœæ planszy
void BoardLocal::clear() {
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			board[i][j].reset();
			shotMap[i][j] = NONE;
		}
	}
	list.clear();
}