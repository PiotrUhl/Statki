#include "UserDllInterface.h"

UserDllInterface::UserDllInterface() {} //konstruktor
UserDllInterface& UserDllInterface::getInstance() { //pobierz instancje klasy
	static UserDllInterface&& instance = UserDllInterface();
	return instance;
}
#pragma region IUserInterface
//przekazuje planszê board do utworzenia, wstrzymuje program do zakoñczenia tworzenia
void UserDllInterface::makeBoard(PlannerLocal* board) {
	//wywo³anie delegaty
}
//pobiera wspó³rzêdne strza³u
Point UserDllInterface::getShotCoords() {
	return callBack.out_getCoords();
}
//poinformuj interfejs o zmianie na planszy
void UserDllInterface::boardChanged(std::list<Board::ShipInfo> shipList, std::vector<std::vector<ShotResult>> shotMap) {
#pragma region shipList
	int shipSize = shipList.size();
	Board::ShipInfo** shipTab = new Board::ShipInfo*[shipSize];
	int i = 0;
	for (auto k : shipList) {
		Board::ShipInfo* temp = new Board::ShipInfo;
		*temp = k;
		shipTab[i++] = temp;
	}
#pragma endregion
#pragma region shotMap
	unsigned char* shotTab = new unsigned char[BOARDSIZE*BOARDSIZE];
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			shotTab[i*BOARDSIZE + j] = static_cast<unsigned char>(shotMap[i][j]);
		}
	}
#pragma endregion
	callBack.out_sendShipsInfo(shipTab, shipSize);
	callBack.out_sendShotMap(shotTab, BOARDSIZE*BOARDSIZE);
	delete[] shipTab;
	delete[] shotTab;
}
//przekazuje informacje o zakoñczeniu gry
void UserDllInterface::gameEnded(char winner) {
	//wywo³anie delegaty
}
#pragma endregion
#include "Game.h"
#include "CreatorBoard.h" //debug
#pragma region IDLLInterface
//uruchamia grê
void UserDllInterface::runProgram(IDllInterface::CallBacks callBacks) {
	callBack = callBacks;
	//Game game(getInstance()); //debug
	//game.run(); //debug
	std::unique_ptr<Board> board = CreatorBoard(10).makeBoard(PlayerType::AI); //debug
	boardChanged(board->getList(), board->getShotMap()); //debug
}

#include "PlannerLocal.h"
//sprawdza mo¿liwoœæ po³o¿enia statku o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
bool UserDllInterface::checkShipPlacement(int shipSize, int x, int y, char direction) {
	return currentPlanner->checkPlacement(shipSize, x, y, direction);
}
//umieszcza statkek o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
bool UserDllInterface::placeShip(int shipSize, int x, int y, char direction) {
	return currentPlanner->place(shipSize, x, y, direction);
}
#pragma endregion