#include "UserDllInterface.h"

UserDllInterface::UserDllInterface() {} //konstruktor
UserDllInterface& UserDllInterface::getInstance() { //pobierz instancje klasy
	static UserDllInterface&& instance = UserDllInterface();
	return instance;
}

#pragma region IUserInterface

//wypisuje na ekranie b��d "error'; "critical" przerywa dzia�anie programu
void UserDllInterface::error(const char* error, bool critical) {
	callBack.out_error(error, critical);
}

//rejestruje id planszy w interfejsie
void UserDllInterface::registerBoard(int nr, int id) {
	callBack.out_registerBoard(nr, id);
}

#include <Windows.h>
//przekazuje plansz� board do utworzenia, wstrzymuje program do zako�czenia tworzenia
void UserDllInterface::makeBoard(PlannerLocal* board) {
	//wywo�anie delegaty
	//callBack.out_error("UserDllInterface::makeBoard() unimplemented!", true);
	//error("UserDllInterface::makeBoard() unimplemented!", true);
	callBack.out_plannerMode();
}

//pobiera wsp�rz�dne strza�u
Point UserDllInterface::getShotCoords() {
	return callBack.out_getCoords();
}

//poinformuj interfejs o zmianie na planszy
void UserDllInterface::boardChanged(int id, std::list<ShipInfo> shipList, std::vector<std::vector<ShotResult>> shotMap) {
	int shipSize = shipList.size();
	ShipInfo** shipTab = new ShipInfo*[shipSize];
	int i = 0;
	for (auto k : shipList) {
		ShipInfo* temp = new ShipInfo;
		*temp = k;
		shipTab[i++] = temp;
	}
	unsigned char* shotTab = new unsigned char[BOARDSIZE*BOARDSIZE];
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			shotTab[i*BOARDSIZE + j] = static_cast<unsigned char>(shotMap[i][j]);
		}
	}
	callBack.out_sendShipsInfo(shipTab, shipSize, id);
	callBack.out_sendShotMap(shotTab, BOARDSIZE*BOARDSIZE, id);
	delete[] shipTab;
	delete[] shotTab;
}

//przekazuje informacje o zako�czeniu gry
void UserDllInterface::gameEnded(char winner) {
	//wywo�anie delegaty
	callBack.out_error("UserDllInterface::gameEnded() unimplemented!", true);
}

#pragma endregion

#include "Game.h"
#include "CreatorBoard.h" //debug
#pragma region IDLLInterface

//uruchamia gr�
void UserDllInterface::runProgram(InitData init, IDllInterface::CallBacks callBacks) {
	callBack = callBacks;
	Game game(init, getInstance());
	game.run();
	//std::unique_ptr<Board> board = CreatorBoard(10, getInstance()).makeBoard(PlayerType::AI); //debug
	//registerBoard(1, board->getId()); //debug
	//boardChanged(board->getId(), board->getList(), board->getShotMap()); //debug
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

#pragma endregion