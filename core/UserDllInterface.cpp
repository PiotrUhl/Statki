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
void UserDllInterface::boardChanged(std::list<Board::ShipInfo> shipList, std::vector<std::vector<bool>> shotMap) {
	int size = shipList.size();
	Board::ShipInfo** tab = new Board::ShipInfo*[size];
	int i = 0;
	for (auto k : shipList) {
		Board::ShipInfo* temp = new Board::ShipInfo;
		*temp = k;
		tab[i++] = temp;
	}
	//todo: dodaæ shotMap
	callBack.out_sendShipsInfo(tab, size);
	delete[] tab;
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
	//Game game; //debug
	//game.run(); //debug
	std::unique_ptr<Board> board = CreatorBoard(10).makeBoard(Game::playerType::AI); //debug
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
//pobiera obraz planszy o numerze 'id'
int* UserDllInterface::getBoardImage(int id) {
	return nullptr;
}
#pragma endregion