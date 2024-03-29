#pragma once
#include "Player.h" //Player
//#include "Board.h" //Board
#include "IUserInterface.h" //IUserInterface
#include "structs.hpp" //PlayerType, ShotResut, Point
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
	//zwraca obraz planszy 'boardId'
	boost::multi_array<unsigned char, 2> getBoardImage(int boardId) const;
	//zwraca obraz punktu 'point' na planszy 'boardId'
	unsigned char getSquareImage(int boardId, Point point) const;
	//zwraca map� strza��w planszy 'boardId'
	boost::multi_array<ShotResult, 2> getShotMap(int boardId) const;
	//zwraca informacj� o strzale w pole 'point' na planszy 'boardId'
	ShotResult getSquareShot(int boardId, Point point) const;
	//zwraca list� informacji o wszystkich statkach na planszy 'boardId'
	std::list<ShipInfo> getShipList(int boardId) const;
	//zwraca informacje o statku le��cym na polu 'point' na planszy 'boardId'
	ShipInfo getSquareShip(int boardId, Point point) const;
	//zwraca liczb� statk�w na planszy 'boardId'
	int getShipCount(int boardId) const;
private:
	//cz�� gry - inicjalizacja
	void initialization();
	//cz�� gry - g��wna p�tla
	char loop();
	//cz�� gry - zako�czenie
	void ending(char winner);
	//inicjalizuje graczy
	void initializePlayers();
	//zwraca wska�nik na plansz� o podanym id; gdy nie znajdzie zwraca nullptr
	Board* findBoardById(int boardId);
	const Board* findBoardById(int boardId) const;
};