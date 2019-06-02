#include "UserDllInterface.h"

UserDllInterface::UserDllInterface() {} //konstruktor
UserDllInterface& UserDllInterface::getInstance() { //pobierz instancje klasy
	static UserDllInterface&& instance = UserDllInterface();
	return instance;
}
#pragma region IUserInterface
//przekazuje plansz� board do utworzenia, wstrzymuje program do zako�czenia tworzenia
void UserDllInterface::makeBoard(PlannerLocal* board) {
	//wywo�anie delegaty
}
//pobiera wsp�rz�dne strza�u
Point UserDllInterface::getShotCoords() {
	return callBack.out_getCoords();
}
//poinformuj interfejs o zmianie na planszy 'id'; waitForRespond wstrzymuje dzia�anie programu do otrzymania odpowiedzi (interfejs odczyta� zmian�)
void UserDllInterface::boardChanged(int id, bool waitForRespond = false) {
	//wywo�anie delegaty
}
//przekazuje informacje o zako�czeniu gry
void UserDllInterface::gameEnded(char winner) {
	//wywo�anie delegaty
}
#pragma endregion
#include "Game.h"
#pragma region IDLLInterface
//uruchamia gr�
void UserDllInterface::runProgram() {
	Game game;
	game.run();
}

#include "PlannerLocal.h"
//sprawdza mo�liwo�� po�o�enia statku o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
bool UserDllInterface::checkShipPlacement(int shipSize, int x, int y, char direction) {
	return currentPlanner->checkPlacement(shipSize, x, y, direction);
}
//umieszcza statkek o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
bool UserDllInterface::placeShip(int shipSize, int x, int y, char direction) {
	return currentPlanner->place(shipSize, x, y, direction);
}
//pobiera obraz planszy o numerze 'id'
int* UserDllInterface::getBoardImage(int id) {
	return nullptr;
}
#pragma endregion