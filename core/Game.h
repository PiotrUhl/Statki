#pragma once
//#include "UserInterface.h"
#include "Player.h" //Player
#include "Board.h" //Board
#include "enums.hpp"
#include <memory> //std::unique_ptr

class Game {
private:
	int BOARDSIZE; //rozmiar planszy
	PlayerType player1Type; //typ gracza 1
	PlayerType player2Type; //typ gracza 2
	std::unique_ptr<Board> board1; //plansza gracza nr 1
	std::unique_ptr<Board> board2; //plansza gracza nr 2
	std::unique_ptr<Player> player1; //gracz nr 1
	std::unique_ptr<Player> player2; //gracz nr 2
public:
	//konstruktor
	Game();
	//destruktor
	~Game();
	//uruchom gr�
	void run();
private:
	//cz�� gry - inicjalizacja
	void initialization();
	//cz�� gry - g��wna p�tla
	char loop();
	//cz�� gry - zako�czenie
	void ending(char winner);
	//inicjalizuje graczy
	void initializePlayers();
};