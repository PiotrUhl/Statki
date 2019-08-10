#include "UserDllInterface.h"

UserDllInterface::UserDllInterface() : currentPlanner(nullptr) {} //konstruktor
UserDllInterface& UserDllInterface::getInstance() { //pobierz instancje klasy
	static UserDllInterface&& instance = UserDllInterface();
	return instance;
}

#pragma region IUserInterface

//wysy³a do interfejsu wiadomoœæ o treœci 'msg' o typie 'type'; je¿eli 'critical' przerywa dzia³anie programu
void UserDllInterface::msg(const char* msg, MsgType type, bool critical) {
	callBack.out_msg(msg, type, critical);
}

//przekazuje planszê 'board' do utworzenia
void UserDllInterface::makeBoard(BoardLocal& board) {
	currentPlanner = std::make_unique<PlannerLocal>(board);
	callBack.out_enterPlannerMode();
}

//pobiera wspó³rzêdne strza³u
Point UserDllInterface::getShotCoords() {
	return callBack.out_getCoords();
}

//event - ruch gracza 'playerId'
void UserDllInterface::event_playerMoved(int playerId) {
	if (callBack.out_event_playerMoved != nullptr)
		callBack.out_event_playerMoved(playerId);
}

//event - ukoñczono tworzenie planszy 'boardId'
void UserDllInterface::event_boardCreated(int boardId) {
	if (callBack.out_event_boardCreated != nullptr)
		callBack.out_event_boardCreated(boardId);
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
//sprawdza mo¿liwoœæ po³o¿enia statku o rozmiarze 'shipSize' w polu 'point', w kierunku 'direction'
bool UserDllInterface::checkShipPlacement(int shipSize, Point point, Direction direction) {
	return currentPlanner->checkPlacement(shipSize, point, direction);
}

//umieszcza statkek o rozmiarze 'shipSize' w polu 'point', w kierunku 'direction'; zwraca rezultat
bool UserDllInterface::placeShip(int shipSize, Point point, Direction direction) {
	return currentPlanner->place(shipSize, point, direction);
}
#include "PlannerLocalAI.h"
//wype³nia planszê losowo u¿ywaj¹c algorytmu
void UserDllInterface::fillRandom() {
	//throw "Not yet implemented!"; //undone: UserDllInterface::fillRandom()
	PlannerLocalAI temp(currentPlanner->getBoard());
	temp.makeBoard();
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

//zapisuje obraz planszy 'boardId' do bufora 'outbuffer'
void UserDllInterface::getBoardImage(unsigned char* outbuffer, int boardId) const {
	boost::multi_array<unsigned char, 2> image = game->getBoardImage(boardId);
	memcpy(outbuffer, image.origin(), image.num_elements()*sizeof(unsigned char));
}
//zwraca obraz punktu 'point' na planszy 'boardId'
unsigned char UserDllInterface::getSquareImage(int boardId, Point point) const {
	return game->getSquareImage(boardId, point);
}

//zapisuje mapê strza³ów planszy 'boardId' do bufora 'outbuffer'
void UserDllInterface::getShotMap(unsigned char* outbuffer, int boardId) const {
	boost::multi_array<ShotResult, 2> shotMap = game->getShotMap(boardId);
	for (int i = 0; i < BOARDSIZE*BOARDSIZE; i++) {
		outbuffer[i] = static_cast<unsigned char>(shotMap.origin()[i]);
	}
}
//zwraca informacjê o strzale w pole 'point' na planszy 'boardId'
ShotResult UserDllInterface::getSquareShot(int boardId, Point point) const {
	return game->getSquareShot(boardId, point);
}

//zwraca informacje o statku le¿¹cym na polu 'point' na planszy 'boardId'
ShipInfo UserDllInterface::getSquareShip(int boardId, Point point) const {
	return game->getSquareShip(boardId, point);
}
//zapisuje informacje o wszystkich statkach na planszy 'boardId' do bufora 'outbuffer'
void UserDllInterface::getShipList(ShipInfo* outbuffer, int boardId) const {
	std::list<ShipInfo> shipList = game->getShipList(boardId);
	auto iter = shipList.begin(); //iterator
	for (size_t i = 0; i < shipList.size(); i++) {
		std::memcpy(&outbuffer[i], &*iter, sizeof(ShipInfo));
		iter++;
	}
}

//zwraca liczbê statków na planszy 'boardId'
int UserDllInterface::getShipCount(int boardId) const {
	return game->getShipCount(boardId);
}
#pragma endregion