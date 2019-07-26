#pragma once
#include "IDllInterface.h"
#include "IUserInterface.h"
#include "Board.h"
#include "Game.h"
#include "structs.hpp"

class UserDllInterface : public IUserInterface/*, public IDllInterface*/ {
#pragma region singleton
	static UserDllInterface&& instance; //jedyna instancja klasy
	UserDllInterface(); //konstruktor
	UserDllInterface(const UserDllInterface&) = delete; //konstruktor kopiuj�cy
	UserDllInterface& operator=(const UserDllInterface&) = delete; //kopiuj�cy operator przypisania
public:
	static UserDllInterface& getInstance(); //pobierz instancje klasy
#pragma endregion
private:
	std::unique_ptr<Game> game; //g��wna klasa gry
	PlannerLocal* currentPlanner; //uchwyt na obecnie wybrany planer //dla PlannerLocal dla CreatorBoard dla PlayerType::HUMAN
	IDllInterface::CallBacks callBack; //struktura wska�nik�w na callBacki
public:
#pragma region IUserInterface	
	//wypisuje na ekranie b��d "error'; "critical" przerywa dzia�anie programu
	void error(const char*, bool) override;
	//rejestruje id planszy w interfejsie
	void registerBoard(int, int) override;
	//przekazuje plansz� board do utworzenia
	void makeBoard(PlannerLocal* planner) override;
	//pobiera wsp�rz�dne strza�u
	Point getShotCoords() override;
	//poinformuj interfejs o zmianie na planszy
	void boardChanged(int, std::list<ShipInfo>, std::array<std::array<ShotResult, BOARDSIZE>, BOARDSIZE>) override;
	//przekazuje informacje o zako�czeniu gry
	void gameEnded(char winner) override;
	//zg�asza do interfejsu wyniki strza�u
	void sendShotInfo(int, Point, ShotResult) override;
#pragma endregion
#pragma region IDLLInterface
	//uruchamia gr�
	void runProgram(InitData, IDllInterface::CallBacks);
	//sprawdza mo�liwo�� po�o�enia statku o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
	bool checkShipPlacement(int shipSize, int x, int y, char direction);
	//umieszcza statkek o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
	bool placeShip(int shipSize, int x, int y, char direction);

	//zwraca gracza obecnie wykonuj�cego ruch (b�d� 0 dla niew�a�ciwej cz�ci gry)
	int getCurrentPlayer() const;
	//zwraca typ gracza 'playerId' b�d� NONE w przypadku niew�a�ciwego gracza
	PlayerType getPlayerType(int playerId) const;
	//zwraca id planszy w kt�r� strzelono jako ostatni� (b�d� 0 je�eli nie strzelano)
	int getLastShotBoard() const;
	//zwraca miejsce ostatniego strza�u w plansz� 'boardId'; dla 'boardId' = 0 zwraca miejsce ostatniego strza�u
	Point getLastShotPoint(int boardId) const;
	//zwraca wynik ostatniego strza�u w plansz� 'boardId'; dla 'boardId' = 0 zwraca wynik ostatniego strza�u
	ShotResult getLastShotResult(int boardId) const;
#pragma endregion
};