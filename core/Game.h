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

	int currentPlayer; //gracz obecnie wykonuj¹cy ruch (0 dla pozosta³ych czêœci gry)
	int lastShotBoard; //plansza w któr¹ strzelano jako ostatni¹
public:
	//konstruktor
	Game(InitData, IUserInterface&);
	//destruktor
	~Game();
	//uruchom grê
	void run();

	//zwraca currentPlayer
	int getCurrentPlayer() const;
	//zwraca typ gracza 'playerId' b¹dŸ NONE w przypadku niew³aœciwego gracza
	PlayerType getPlayerType(int playerId) const;
	//zwraca lastShotBoard
	int getLastShotBoard() const;
	//zwraca miejsce ostatniego strza³u w planszê 'boardId'; (BOARDSIZE, BOARDSIZE) w razie b³êdu
	Point getLastShotPoint(int boardId) const;
	//zwraca wynik ostatniego strza³u w planszê 'boardId'
	ShotResult getLastShotResult(int boardId) const;
private:
	//czêœæ gry - inicjalizacja
	void initialization();
	//czêœæ gry - g³ówna pêtla
	char loop();
	//czêœæ gry - zakoñczenie
	void ending(char winner);
	//inicjalizuje graczy
	void initializePlayers();
};