#include "PlayerAI.h"

//konstruktor
PlayerAI::PlayerAI(int _BOARDSIZE, Board& _myBoard, Board& _otherBoard) : Player(_BOARDSIZE, _myBoard, _otherBoard), shootableCount(BOARDSIZE*BOARDSIZE), shootableMap(BOARDSIZE, std::vector<bool>(BOARDSIZE, true)) {}

//destruktor
PlayerAI::~PlayerAI() {}

//gracz wykonuje swój ruch
void PlayerAI::move() {
	if (finishMode == false) {
		Point point = chooseSquare();
		Board::ShotResult result = otherBoard.shot(point.x, point.y);
		if (result == ShotResult::HIT)
			setFinishMode(point);
		updateShootableMap(point);
	}
	else {
		//finishMode
	}
}

void PlayerAI::setFinishMode(Point point) {
	finishMode = true;
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