#pragma once
#include "Player.h" //Player
//#include "Board.h" //Board
#include "IUserInterface.h" //IUserInterface
#include "structs.hpp" //PlayerType, ShotResut
#include "Point.hpp" //Point
#include <memory> //std::unique_ptr

class Game {
private:
	PlayerType player1Type; //typ gracza 1
	PlayerType player2Type; //typ gracza 2
	std::unique_ptr<Board> board1; //plansza gracza nr 1
	std::unique_ptr<Board> board2; //plansza gracza nr 2
	std::unique_ptr<Player> player1; //gracz nr 1
	std::unique_ptr<Player> player2; //gracz nr 2
	IUserInterface& mainInterface; //interfejs do komunikacji z graczem

	int currentPlayer; //gracz obecnie wykonuj�cy ruch (0 dla pozosta�ych cz�ci gry)
	int lastShotBoard; //plansza w kt�r� strzelano jako ostatni�
public:
	//konstruktor
	Game(InitData, IUserInterface&);
	//destruktor
	~Game();
	//uruchom gr�
	void run();

	//zwraca currentPlayer
	int getCurrentPlayer() const;
	//zwraca typ gracza 'playerId' b�d� NONE w przypadku niew�a�ciwego gracza
	PlayerType getPlayerType(int playerId) const;
	//zwraca lastShotBoard
	int getLastShotBoard() const;
	//zwraca miejsce ostatniego strza�u w plansz� 'boardId'; (BOARDSIZE, BOARDSIZE) w razie b��du
	Point getLastShotPoint(int boardId) const;
	//zwraca wynik ostatniego strza�u w plansz� 'boardId'
	ShotResult getLastShotResult(int boardId) const;
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