#include "BoardLocal.h"

//konstruktor
BoardLocal::BoardLocal() : board(boost::extents[BOARDSIZE][BOARDSIZE]) {}

//destruktor
BoardLocal::~BoardLocal() {}

//przeci¹¿ony operator []
boost::multi_array<Square, 2>::array_view<1>::type BoardLocal::operator[](size_t index) {
	return board[boost::indices[index][boost::multi_array_types::index_range(0, BOARDSIZE)]];
}

#include "Ship.h"

//umieszcza statkek o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
bool BoardLocal::placeShip(int shipSize, int x, int y, char direction) {
	if ((x < 0) || (y < 0) || (direction == 'H' && x + shipSize - 1 >= BOARDSIZE) || (direction == 'V' && y + shipSize - 1 >= BOARDSIZE)) //próba umieszczenia statku poza plansz¹
		return false;
	std::shared_ptr<Ship> newShip = std::make_shared<Ship>(shipSize, Point{x, y}, direction);
	if (direction == 'H')
		for (int i = 0; i < shipSize; i++) {
			board[y][x + i].set(newShip);
			newShip->addLocation(&(board[y][x + i]));
		}
	else if (direction == 'V')
		for (int i = 0; i < shipSize; i++) {
			board[y + i][x].set(newShip);
			newShip->addLocation(&(board[y + i][x]));
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

//zwraca informacje o statku le¿¹cym na polu 'point'
ShipInfo BoardLocal::getSquareShip(Point point) const {
	return board[point.y][point.x].getShipInfo();
}

//zwraca obraz planszy
boost::multi_array<char, 2> BoardLocal::getImage() {
	boost::multi_array<char, 2> image(boost::extents[BOARDSIZE][BOARDSIZE]);
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			image[i][j] = fillImageSquare(j, i);
		}
	}
	return image;
}

//zwraca obraz pola 'point'
unsigned char BoardLocal::getSquareImage(Point point) {
	return fillImageSquare(point.x, point.y);
}
//todo: scaliæ getSquareImage i fillImageSquare
//zwraca obraz pola ("x", "y")
char BoardLocal::fillImageSquare(int x, int y) {
	if (board[y][x] == nullptr) { //pole puste
		if (board[y][x].getShooted()) { //pole puste i postrzelone
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
		if (board[y][x].getShooted()) { //statek postrzelony
			if (board[y][x].getSunk()) { //statek zatopiony
				ret += 200;
			}
			else { //statek p³onie
				ret += 100;
			}
		}
		ret += board[y][x].getSize();
		return ret;
	}
	return 255; //b³¹d
}

//okreœla kierunek statku le¿¹cego na polu  ("x", "y")
char BoardLocal::findDirection(int x, int y) {
	if (x > 0 && board[y][x - 1] != nullptr)
		return 'H';
	if (x < BOARDSIZE - 1 && board[y][x + 1] != nullptr)
		return 'H';
	if (y > 0 && board[y - 1][x] != nullptr)
		return 'V';
	if (y < BOARDSIZE - 1 && board[y + 1][x] != nullptr)
		return 'V';
	return 255; //b³ad
}

//strzela w pole planszy o wspó³rzêdnych (x, y); zwraca rezultat
ShotResult BoardLocal::shot(int x, int y) {
	lastShotPoint = Point{x, y};
	shotMap[y][x] = board[y][x].shot(); //strzel w dane pole
	if (shotMap[y][x] == ShotResult::SUNK)
		unsunkShips--;
	lastShotResult = shotMap[y][x];
	return shotMap[y][x];
}

//usuwa ca³¹ zawartoœæ planszy
void BoardLocal::clear() {
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			board[i][j].reset();
			shotMap[i][j] = ShotResult::NONE;
		}
	}
	list.clear();
}