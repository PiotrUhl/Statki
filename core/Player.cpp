#include "Player.h"

//konstruktor
Player::Player(int _BOARDSIZE, Board& _myBoard, Board& _otherBoard) : BOARDSIZE(_BOARDSIZE), myBoard(_myBoard), otherBoard(_otherBoard) {}

//destruktor
Player::~Player() {}

//gracz wykonuje sw�j ruch
//void Player::move() {}

//zwraca miejsce ostatniego strza�u
Point Player::getLastShotPoint() {
	return lastShotPoint;
}

//zwraca rezultat ostatniego strza�u
ShotResult Player::getLastShotResult() {
	return lastShotResult;
}

//zwraca ID swojej planszy
int Player::getMyBoardId() {
	return myBoard.getId();
}

//zwraca ID planszy przeciwnika
int Player::getOtherBoardId() {
	return otherBoard.getId();
}