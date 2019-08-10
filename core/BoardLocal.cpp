#include "BoardLocal.h"

//konstruktor
BoardLocal::BoardLocal() : board(boost::extents[BOARDSIZE][BOARDSIZE]) {}

//destruktor
BoardLocal::~BoardLocal() {}

//przeci¹¿ony operator []
boost::multi_array<Square, 2>::array_view<1>::type BoardLocal::operator[](size_t index) {
	return board[boost::indices[index][boost::multi_array_types::index_range(0, BOARDSIZE)]];
}
Square & BoardLocal::operator[](Point point) {
	return board[point.y][point.x];
}

#include "Ship.h"

//umieszcza statkek o rozmiarze "shipSize" w polu 'point', w kierunku direction; zwraca rezultat
bool BoardLocal::placeShip(int shipSize, Point point, Direction direction) {
	if ((point.x < 0) || (point.y < 0) || (direction == Direction::HORIZONTAL && point.x + shipSize - 1 >= BOARDSIZE) || (direction == Direction::VERTICAL && point.y + shipSize - 1 >= BOARDSIZE)) //próba umieszczenia statku poza plansz¹
		return false;
	std::shared_ptr<Ship> newShip = std::make_shared<Ship>(shipSize, point, direction);
	if (direction == Direction::HORIZONTAL)
		for (int i = 0; i < shipSize; i++) {
			board[point.y][point.x + i].set(newShip);
			newShip->addLocation(&(board[point.y][point.x + i]));
		}
	else if (direction == Direction::VERTICAL)
		for (int i = 0; i < shipSize; i++) {
			board[point.y + i][point.x].set(newShip);
			newShip->addLocation(&(board[point.y + i][point.x]));
		}
	else
		throw (std::invalid_argument("Incorrect ship direction"));
	unsunkShips++;
	shipCount++;
	list.push_back(newShip);
	return true;
}

//usuwa statkek z pola 'point'
bool BoardLocal::removeShip(Point point) {
	if (board[point.y][point.x].getSunk() == false) {
		unsunkShips--;
	}
	list.remove_if([point](std::shared_ptr<Ship> v) { //usuñ statek z listy
		Point vPoint = v->getPoint();
		if (vPoint.x == point.x && vPoint.y == point.y)
			return true;
		else
			return false;
	});
	shipCount--;
	return board[point.y][point.x].removeShip();
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

//strzela w pole 'point'; zwraca rezultat
ShotResult BoardLocal::shot(Point point) {
	lastShotPoint = point;
	shotMap[point.y][point.x] = board[point.y][point.x].shot(); //strzel w dane pole
	if (shotMap[point.y][point.x] == ShotResult::SUNK)
		unsunkShips--;
	lastShotResult = shotMap[point.y][point.x];
	return shotMap[point.y][point.x];
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