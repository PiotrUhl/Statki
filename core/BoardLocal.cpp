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

//umieszcza statkek o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction; zwraca rezultat
bool BoardLocal::placeShip(int shipSize, int x, int y, Direction direction) {
	if ((x < 0) || (y < 0) || (direction == Direction::HORIZONTAL && x + shipSize - 1 >= BOARDSIZE) || (direction == Direction::VERTICAL && y + shipSize - 1 >= BOARDSIZE)) //próba umieszczenia statku poza plansz¹
		return false;
	std::shared_ptr<Ship> newShip = std::make_shared<Ship>(shipSize, Point{x, y}, direction);
	if (direction == Direction::HORIZONTAL)
		for (int i = 0; i < shipSize; i++) {
			board[y][x + i].set(newShip);
			newShip->addLocation(&(board[y][x + i]));
		}
	else if (direction == Direction::VERTICAL)
		for (int i = 0; i < shipSize; i++) {
			board[y + i][x].set(newShip);
			newShip->addLocation(&(board[y + i][x]));
		}
	else
		throw (std::invalid_argument("Incorrect ship direction"));
	unsunkShips++;
	shipCount++;
	list.push_back(newShip);
	return true;
}

//usuwa statkek z pola (x, y)
bool BoardLocal::removeShip(int x, int y) {
	if (board[y][x].getSunk() == false) {
		unsunkShips--;
	}
	list.remove_if([x, y](std::shared_ptr<Ship> v) { //usuñ statek z listy
		Point point = v->getPoint();
		if (point.x == x && point.y == y)
			return true;
		else
			return false;
	});
	shipCount--;
	return board[y][x].removeShip();
}

//zwraca informacje o statku le¿¹cym na polu 'point'
ShipInfo BoardLocal::getSquareShip(Point point) const {
	return board[point.y][point.x].getShipInfo();
}

//zwraca obraz planszy
boost::multi_array<unsigned char, 2> BoardLocal::getImage() const {
	boost::multi_array<unsigned char, 2> image(boost::extents[BOARDSIZE][BOARDSIZE]);
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			image[i][j] = getSquareImage(Point{ j, i });
		}
	}
	return image;
}

//zwraca obraz pola 'point'
unsigned char BoardLocal::getSquareImage(Point point) const {
	if (board[point.y][point.x] == nullptr) { //pole puste
		if (board[point.y][point.x].getShooted()) { //pole puste i postrzelone
			return 1;
		}
		else { //pole puste i niepostrzelone
			return 0;
		}
	}
	else { //pole niepuste
		char ret = 0;
		if (board[point.y][point.x].getDirection() == Direction::HORIZONTAL) { //statek poziomo
			ret += 10;
		}
		else { //statek pionowo
			ret += 20;
		}
		if (board[point.y][point.x].getShooted()) { //statek postrzelony
			if (board[point.y][point.x].getSunk()) { //statek zatopiony
				ret += 200;
			}
			else { //statek p³onie
				ret += 100;
			}
		}
		ret += board[point.y][point.x].getSize();
		return ret;
	}
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

//zwraca listê informacji o wszystkich statkach na planszy
std::list<ShipInfo> BoardLocal::getShipList() const {
	std::list<ShipInfo> ret;
	for (auto k : list) {
		ret.push_back(k->getShipInfo());
	}
	return ret;
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
	shipCount = 0;
	unsunkShips = 0;
}