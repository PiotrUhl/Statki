#include "Player.h"

//konstruktor
Player::Player(Board& _myBoard, Board& _otherBoard) : myBoard(_myBoard), otherBoard(_otherBoard), lastShotPoint(Point({ BOARDSIZE, BOARDSIZE })) {}

//destruktor
Player::~Player() {}

//gracz wykonuje swój ruch
//void Player::move() {}

//zwraca miejsce ostatniego strza³u
Point Player::getLastShotPoint() {
	return lastShotPoint;
}

//zwraca rezultat ostatniego strza³u
ShotResult Player::getLastShotResult() {
	return lastShotResult;
}