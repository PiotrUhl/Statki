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
	UserDllInterface(const UserDllInterface&) = delete; //konstruktor kopiuj¹cy
	UserDllInterface& operator=(const UserDllInterface&) = delete; //kopiuj¹cy operator przypisania
public:
	static UserDllInterface& getInstance(); //pobierz instancje klasy
#pragma endregion
private:
	std::unique_ptr<Game> game; //g³ówna klasa gry
	PlannerLocal* currentPlanner; //uchwyt na obecnie wybrany planer //dla PlannerLocal dla CreatorBoard dla PlayerType::HUMAN
	IDllInterface::CallBacks callBack; //struktura wskaŸników na callBacki
public:
#pragma region IUserInterface	
	//wypisuje na ekranie b³¹d "error'; "critical" przerywa dzia³anie programu
	void error(const char*, bool) override;
	//rejestruje id planszy w interfejsie
	void registerBoard(int, int) override;
	//przekazuje planszê board do utworzenia
	void makeBoard(PlannerLocal* planner) override;
	//pobiera wspó³rzêdne strza³u
	Point getShotCoords() override;
	//poinformuj interfejs o zmianie na planszy
	void boardChanged(int, std::list<ShipInfo>, std::array<std::array<ShotResult, BOARDSIZE>, BOARDSIZE>) override;
	//przekazuje informacje o zakoñczeniu gry
	void gameEnded(char winner) override;
	//zg³asza do interfejsu wyniki strza³u
	void sendShotInfo(int, Point, ShotResult) override;
#pragma endregion
#pragma region IDLLInterface
	//uruchamia grê
	void runProgram(InitData, IDllInterface::CallBacks);
	//sprawdza mo¿liwoœæ po³o¿enia statku o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
	bool checkShipPlacement(int shipSize, int x, int y, char direction);
	//umieszcza statkek o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
	bool placeShip(int shipSize, int x, int y, char direction);

	//zwraca gracza obecnie wykonuj¹cego ruch (b¹dŸ 0 dla niew³aœciwej czêœci gry)
	int getCurrentPlayer() const;
	//zwraca typ gracza 'playerId' b¹dŸ NONE w przypadku niew³aœciwego gracza
	PlayerType getPlayerType(int playerId) const;
	//zwraca id planszy w któr¹ strzelono jako ostatni¹ (b¹dŸ 0 je¿eli nie strzelano)
	int getLastShotBoard() const;
	//zwraca miejsce ostatniego strza³u w planszê 'boardId'; dla 'boardId' = 0 zwraca miejsce ostatniego strza³u
	Point getLastShotPoint(int boardId) const;
	//zwraca wynik ostatniego strza³u w planszê 'boardId'; dla 'boardId' = 0 zwraca wynik ostatniego strza³u
	ShotResult getLastShotResult(int boardId) const;
#pragma endregion
};