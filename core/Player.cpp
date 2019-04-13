#include "Player.h"

//konstruktor
Player::Player(int _BOARD_SIZE) : BOARD_SIZE(_BOARD_SIZE) {}

//destruktor
Player::~Player() {}

//zwraca wska�nik na swoj� plansz�
Board* Player::getMyBoard() {
	return myBoard.get();
}

//ustawia wska�nik na plansz� przeciwnika
void Player::setOtherBoard(Board* _otherBoard) {
	otherBoard = _otherBoard;
}

//gracz wykonuje sw�j ruch
void Player::move() {}