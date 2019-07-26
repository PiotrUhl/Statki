#include "UserDllInterface.h"

UserDllInterface::UserDllInterface() {} //konstruktor
UserDllInterface& UserDllInterface::getInstance() { //pobierz instancje klasy
	static UserDllInterface&& instance = UserDllInterface();
	return instance;
}

#pragma region IUserInterface

//wypisuje na ekranie b³¹d "error'; "critical" przerywa dzia³anie programu
void UserDllInterface::error(const char* error, bool critical) {
	callBack.out_error(error, critical);
}

//rejestruje id planszy w interfejsie
void UserDllInterface::registerBoard(int nr, int id) {
	callBack.out_registerBoard(nr, id);
}

//przekazuje planszê board do utworzenia, wstrzymuje program do zakoñczenia tworzenia
void UserDllInterface::makeBoard(PlannerLocal* planner) {
	currentPlanner = planner;
	callBack.out_plannerMode();
}

//pobiera wspó³rzêdne strza³u
Point UserDllInterface::getShotCoords() {
	return callBack.out_getCoords();
}

//poinformuj interfejs o zmianie na planszy
void UserDllInterface::boardChanged(int id, std::list<ShipInfo> shipList, boost::multi_array<ShotResult, 2> shotMap) {
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
	for (int i = 0; i < shipSize; i++) {
		delete[] shipTab[i];
	}
	delete[] shipTab;
	delete[] shotTab;
}

//przekazuje informacje o zakoñczeniu gry
void UserDllInterface::gameEnded(char winner) {
	//wywo³anie delegaty
	callBack.out_error("UserDllInterface::gameEnded() unimplemented!", true);
}

//zg³asza do interfejsu wyniki strza³u
void UserDllInterface::sendShotInfo(int id, Point point, ShotResult result) {
	callBack.out_sendShotInfo(id, point, result);
}

#pragma endregion
#pragma region IDLLInterface

//uruchamia grê
void UserDllInterface::runProgram(InitData init, IDllInterface::CallBacks callBacks) {
	callBack = callBacks;
	game = std::make_unique<Game>(init, getInstance());
	game->run();
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

//zwraca gracza obecnie wykonuj¹cego ruch (b¹dŸ 0 dla niew³aœciwej czêœci gry)
int UserDllInterface::getCurrentPlayer() const {
	return game->getCurrentPlayer();
}

//zwraca typ gracza 'playerId' b¹dŸ NONE w przypadku niew³aœciwego gracza
PlayerType UserDllInterface::getPlayerType(int playerId) const {
	return game->getPlayerType(playerId);
}

//zwraca id planszy w któr¹ strzelono jako ostatni¹ (b¹dŸ 0 je¿eli nie strzelano)
int UserDllInterface::getLastShotBoard() const {
	return game->getLastShotBoard();
}

//zwraca miejsce ostatniego strza³u w planszê 'boardId'; dla 'boardId' = 0 zwraca miejsce ostatniego strza³u
Point UserDllInterface::getLastShotPoint(int boardId) const {
	if (boardId == 0)
		boardId = getLastShotBoard();
	return game->getLastShotPoint(boardId);
}

//zwraca wynik ostatniego strza³u w planszê 'boardId'; dla 'boardId' = 0 zwraca wynik ostatniego strza³u
ShotResult UserDllInterface::getLastShotResult(int boardId) const {
	if (boardId == 0)
		boardId = getLastShotBoard();
	return game->getLastShotResult(boardId);
}

#pragma endregion