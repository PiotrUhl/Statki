#include "Player.h"

//konstruktor
Player::Player(int _BOARD_SIZE) : BOARD_SIZE(_BOARD_SIZE) {}

//destruktor
Player::~Player() {}

//zwraca wskaŸnik na swoj¹ planszê
Board* Player::getMyBoard() {
	return myBoard.get();
}

//ustawia wskaŸnik na planszê przeciwnika
void Player::setOtherBoard(Board* _otherBoard) {
	otherBoard = _otherBoard;
}

//gracz wykonuje swój ruch
void Player::move() {}