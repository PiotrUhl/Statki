#include "UserDllInterface.h"

UserDllInterface::UserDllInterface() {} //konstruktor
UserDllInterface& UserDllInterface::getInstance() { //pobierz instancje klasy
	static UserDllInterface&& instance = UserDllInterface();
	return instance;
}
#pragma region IUserInterface
//przekazuje planszê board do utworzenia, wstrzymuje program do zakoñczenia tworzenia
void UserDllInterface::makeBoard(Board& board) {

}
//zwraca wspó³rzêdn¹ x strza³u
int UserDllInterface::getShotCoordX() {
	return 0;
}
//zwraca wspó³rzêdn¹ y strza³u
int UserDllInterface::getShotCoordY() {
	return 0;
}
//poinformuj interfejs o zmianie na planszy 'id'; waitForRespond wstrzymuje dzia³anie programu do otrzymania odpowiedzi (interfejs odczyta³ zmianê)
void UserDllInterface::boardChanged(int id, bool waitForRespond = false) {

}
//przekazuje informacje o zakoñczeniu gry
void UserDllInterface::gameEnded(char winner) {

}
#pragma endregion
#include "Game.h"
#pragma region IDLLInterface
//uruchamia grê
void UserDllInterface::runProgram() {
	Game game;
	game.run();
}
//sprawdza czy ustawiona jest flaga MakeBoard (¿¹danie utworzenia planszy)
bool UserDllInterface::checkFlagMakeBoard() {
	return false;
}
//sprawdza mo¿liwoœæ po³o¿enia statku o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
bool UserDllInterface::checkShipPlacement(int shipSize, int x, int y, char direction) {
	return false;
}
//umieszcza statkek o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
bool UserDllInterface::placeShip(int shipSize, int x, int y, char direction) {
	return false;
}
//ustawia flagê BoardMade (plansza jest utworzona)
bool UserDllInterface::setFlagBoardMade() {
	return false;
}
//sprawdza czy ustawiona jest flaga GiveCoors (¿¹danie przekazania wspó³rzêdnych strza³u)
bool UserDllInterface::checkFlagGiveCoords() {
	return false;
}
//ustawia wspó³rzêdn¹ x strza³u
int UserDllInterface::setShotCoordX() {
	return 0;
}
//ustawia wspó³rzêdn¹ Y strza³u
int UserDllInterface::setShotCoordy() {
	return 0;
}
//ustawia flagê CoordsGiven (wspó³rzêdne przekazane)
bool UserDllInterface::setFlagCoordsGiven() {
	return false;
}
//sprawdza czy ustawiona jest flaga BoardChanged (zg³oszeznie zmiany na planszy); zwraca id zmienionej planszy
int UserDllInterface::checkFlagBoardChanged() {
	return 0;
}
//pobiera obraz planszy o numerze 'id'
int* UserDllInterface::getBoardImage(int id) {
	return nullptr;
}
//resetuje flagê BoardChanged (zg³oszeznie zmiany na planszy)
void UserDllInterface::resetFlagBoardChanged() {

}
//sprawdza czy ustawiona jest flaga GameEnded (gra zakoñczona); zwraca numer zwyciêzcy
char UserDllInterface::checkFlagGameEnded() {
	return 0;
}
#pragma endregion