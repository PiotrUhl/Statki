#include "PlayerAI.h"

//konstruktor
PlayerAI::PlayerAI(int _BOARDSIZE, Board& _myBoard, Board& _otherBoard) : Player(_BOARDSIZE, _myBoard, _otherBoard), shootableCount(BOARDSIZE*BOARDSIZE), shootableMap(BOARDSIZE, std::vector<bool>(BOARDSIZE, true)), finishMode(false) {}

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
		updateShootableMap(point);
		//lastShotPoint = point;
		lastShotPoint.x = point.x;
		lastShotPoint.y = point.y;
		lastShotResult = result;
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
			}
			else if (point.y == finishStart.y) { //trafiony w jednym poziomie z pocz¹tkiem => statek u³o¿ony poziomo
				finishList.remove_if([point](Point v) { //usuñ wszystkie punkty nie le¿¹ce w tym poziomie
					if (v.y != point.y)
						return true;
					else
						return false;
				});
			}
		}
		updateShootableMap(point);
		//lastShotPoint = point;
		lastShotPoint.x = point.x;
		lastShotPoint.y = point.y;
		lastShotResult = result;
	}
}

//przechodzi w tryb wykañczania z pocz¹tkiem w punkcie point
void PlayerAI::setFinishMode(Point point) {
	finishMode = true;
	finishStart = point;
	if (point.x - 1 >= 0)
		finishList.push_back(Point(point.x - 1, point.y));
	if (point.x + 1 < BOARDSIZE)
		finishList.push_back(Point(point.x + 1, point.y));
	if (point.y - 1 >= 0)
		finishList.push_back(Point(point.x, point.y - 1));
	if (point.y + 1 < BOARDSIZE)
		finishList.push_back(Point(point.x, point.y + 1));
}

//losuje punkt w którym mo¿e znajdowaæ siê statek
PlayerAI::Point PlayerAI::chooseSquare() {
	int rand = randomNumber(shootableCount);
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			if (--rand == 0)
				return Point(j, i);
		}
	}
	return Point(-1, -1); //error
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
void PlayerAI::updateShootableMap(Point point) {
	for (int i = point.y - 1; i <= point.y + 1; i++) {
		for (int j = point.x - 1; j <= point.x + 1; j++) {
			if (i < 0 || i >= BOARDSIZE || j < 0 || j >= BOARDSIZE)
				continue;
			shootableMap.at(i).at(j) = false;
		}
	}
}

//losuje losow¹ liczbê naturaln¹ z zakresu <1, b>
int PlayerAI::randomNumber(int b) {
	return (rand() % b) + 1;
}