#include "PlayerAI.h"

//konstruktor
PlayerAI::PlayerAI(Board& _myBoard, Board& _otherBoard) : Player(_myBoard, _otherBoard), shootableCount(BOARDSIZE*BOARDSIZE), finishMode(false) {
	for (auto k : shootableMap) {
		k.fill(true);
	}
}

//destruktor
PlayerAI::~PlayerAI() {}

//przeci¹¿ony operator porównania
bool PlayerAI::Point::operator==(const Point& other) {
	if (x == other.x && y == other.y)
		return true;
	else
		return false;
}

//gracz wykonuje swój ruch
void PlayerAI::move() {
	if (finishMode == false) {
		Point point = chooseSquare();
		ShotResult result = otherBoard.shot(point.x, point.y);
		if (result == ShotResult::HIT)
			setFinishMode(point);
		updateShootableMap(point, result);
		//lastShotPoint = point;
		lastShotPoint.y = point.y;
		lastShotPoint.x = point.x;
		lastShotResult = result;;
	}
	else {
		Point point = chooseFinish();
		ShotResult result = otherBoard.shot(point.x, point.y);
		finishList.remove(point); //usuñ punkt z listy
		if (result == ShotResult::SUNK) {
			finishMode = false;
			finishList.clear();
		}
		else if (result == ShotResult::HIT) {
			if (point.x == finishStart.x) { //trafiony w jednym pionie z pocz¹tkiem => statek u³o¿ony pionowo
				finishList.remove_if([point](Point v) { //usuñ wszystkie punkty nie le¿¹ce w tym pionie
					if (v.x != point.x)
						return true;
					else
						return false;
				});
				if (point.y > finishStart.y) { //strzelono nad punktem pocz¹tkowym - dodaj do listy punkt nad punktem w który strzelono
					if (point.y + 1 < BOARDSIZE && shootableMap[point.y + 1][point.x]) {
						Point newPoint;
						newPoint.x = point.x;
						newPoint.y = point.y + 1;
						finishList.push_back(newPoint);
					}
				}
				else {
					if (point.y - 1 >= 0 && shootableMap[point.y - 1][point.x]) { //strzelono pod punktem pocz¹tkowym - dodaj do listy punkt pod punktem w który strzelono
						Point newPoint;
						newPoint.x = point.x;
						newPoint.y = point.y - 1;
						finishList.push_back(newPoint);
					}
				}
			}
			else if (point.y == finishStart.y) { //trafiony w jednym poziomie z pocz¹tkiem => statek u³o¿ony poziomo
				finishList.remove_if([point](Point v) { //usuñ wszystkie punkty nie le¿¹ce w tym poziomie
					if (v.y != point.y)
						return true;
					else
						return false;
				});
				if (point.x > finishStart.x) { //strzelono na prawo od punktu pocz¹tkowego - dodaj do listy punkt na prawo od punktu w który strzelono
					if (point.x + 1 < BOARDSIZE && shootableMap[point.y][point.x + 1]) {
						Point newPoint;
						newPoint.x = point.x + 1;
						newPoint.y = point.y;
						finishList.push_back(newPoint);
					}
				}
				else {
					if (point.x - 1 >= 0 && shootableMap[point.y][point.x - 1]) { //strzelono na lewo od punktu pocz¹tkowego - dodaj do listy punkt na lewo od punktu w który strzelono
						Point newPoint;
						newPoint.x = point.x - 1;
						newPoint.y = point.y;
						finishList.push_back(newPoint);
					}
				}
			}
		}
		updateShootableMap(point, result);
		//lastShotPoint = point;
		lastShotPoint.y = point.y;
		lastShotPoint.x = point.x;
		lastShotResult = result;
	}
}

//przechodzi w tryb wykañczania z pocz¹tkiem w punkcie point
void PlayerAI::setFinishMode(Point point) {
	finishMode = true;
	finishStart = point;
	if (point.x - 1 >= 0)
		if (shootableMap[point.y][point.x - 1])
			finishList.push_back(Point(point.x - 1, point.y));
	if (point.x + 1 < BOARDSIZE)
		if (shootableMap[point.y][point.x + 1])
			finishList.push_back(Point(point.x + 1, point.y));
	if (point.y - 1 >= 0)
		if (shootableMap[point.y - 1][point.x])
			finishList.push_back(Point(point.x, point.y - 1));
	if (point.y + 1 < BOARDSIZE)
		if (shootableMap[point.y + 1][point.x])
			finishList.push_back(Point(point.x, point.y + 1));
}

//losuje punkt w którym mo¿e znajdowaæ siê statek
PlayerAI::Point PlayerAI::chooseSquare() {
	int rand = randomNumber(shootableCount);
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			if (shootableMap[i][j])
				if (--rand == 0)
					return Point(j, i);
		}
	}
	throw "chooseSquare() error";
}

//losuje punkt spoœród punktów w których mo¿e znajdowaæ siê reszta postrzelonego statku
PlayerAI::Point PlayerAI::chooseFinish() {
	int rand = randomNumber(finishList.size());
	auto iter = finishList.begin();
	for (int  i = 1; i < rand; i++) {
		iter++;
	}
	return *iter;
}

//uzupe³nia tablicê shootableMap o wyniki strza³u w point
void PlayerAI::updateShootableMap(Point point, ShotResult result) {
	if (result == ShotResult::MISS) {
		if (shootableMap.at(point.y).at(point.x)) {
			shootableMap.at(point.y).at(point.x) = false;
			shootableCount--;
		}
	}
	else {
		for (int i = point.y - 1; i <= point.y + 1; i++) {
			for (int j = point.x - 1; j <= point.x + 1; j++) {
				if (i < 0 || i >= BOARDSIZE || j < 0 || j >= BOARDSIZE)
					continue;
				if (shootableMap.at(i).at(j)) {
					shootableMap.at(i).at(j) = false;
					shootableCount--;
				}
			}
		}
	}
}

//losuje losow¹ liczbê naturaln¹ z zakresu <1, b>
int PlayerAI::randomNumber(int b) {
	if (b < 1)
		throw "Trying find random number from range 1:0";
	return (rand() % b) + 1;
}