#include "Player.h"

//konstruktor
Player::Player(int _BOARDSIZE, Board& _myBoard, Board& _otherBoard) : BOARDSIZE(_BOARDSIZE), myBoard(_myBoard), otherBoard(_otherBoard) {}

//destruktor
Player::~Player() {}

//gracz wykonuje sw�j ruch
void Player::move() {}