#pragma once
#include "IDllInterface.h"
#include "IUserInterface.h"
#include "Board.h"
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
	int BOARDSIZE = 10; //rozmiar planszy //debug initialization
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
	//zwraca wsp�rz�dne strza�u
	Point getShotCoords() override;
	//poinformuj interfejs o zmianie na planszy
	void boardChanged(int, std::list<ShipInfo>, std::vector<std::vector<ShotResult>>) override;
	//przekazuje informacje o zako�czeniu gry
	void gameEnded(char winner) override;
#pragma endregion
#pragma region IDLLInterface
	//uruchamia gr�
	void runProgram(InitData, IDllInterface::CallBacks);
	//sprawdza mo�liwo�� po�o�enia statku o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
	bool checkShipPlacement(int shipSize, int x, int y, char direction);
	//umieszcza statkek o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
	bool placeShip(int shipSize, int x, int y, char direction);
#pragma endregion
};