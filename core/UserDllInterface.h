#pragma once
#include "IDllInterface.h"
#include "IUserInterface.h"
#include "Board.h"
#include "enums.hpp"

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
	int BOARDSIZE = 10; //rozmiar planszy //debug initialization
	PlannerLocal* currentPlanner; //uchwyt na obecnie wybrany planer //dla PlannerLocal dla CreatorBoard dla PlayerType::HUMAN
	IDllInterface::CallBacks callBack; //struktura wskaŸników na callBacki
public:
#pragma region IUserInterface	
	//rejestruje id planszy w interfejsie
	void registerBoard(int, int) override;
	//przekazuje planszê board do utworzenia, wstrzymuje program do zakoñczenia tworzenia
	void makeBoard(PlannerLocal* planner) override;
	//zwraca wspó³rzêdne strza³u
	Point getShotCoords() override;
	//poinformuj interfejs o zmianie na planszy
	void boardChanged(int, std::list<Board::ShipInfo>, std::vector<std::vector<ShotResult>>) override;
	//przekazuje informacje o zakoñczeniu gry
	void gameEnded(char winner) override;
#pragma endregion
#pragma region IDLLInterface
	//uruchamia grê
	void runProgram(IDllInterface::CallBacks);
	//sprawdza mo¿liwoœæ po³o¿enia statku o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
	bool checkShipPlacement(int shipSize, int x, int y, char direction);
	//umieszcza statkek o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
	bool placeShip(int shipSize, int x, int y, char direction);
#pragma endregion
};