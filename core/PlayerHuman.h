#pragma once
#include "Player.h"
#include "IUserInterface.h"
#include <stdexcept>      // std::out_of_range; std::logic_error
class PlayerHuman :	public Player {
	IUserInterface& userInterface; //interfejs u¿ytkownika
public:
	//konstruktor
	PlayerHuman(IUserInterface&, Board& _myBoard, Board& _otherBoard);
	//destruktor
	~PlayerHuman();
	//gracz wykonuje swój ruch (IUserInterface In)
	void move() override;
};

