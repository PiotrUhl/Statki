#include "UserDllInterface.h"

UserDllInterface::UserDllInterface() {} //konstruktor
UserDllInterface& UserDllInterface::getInstance() { //pobierz instancje klasy
	static UserDllInterface&& instance = UserDllInterface();
	return instance;
}
#pragma region IUserInterface
//przekazuje planszê board do utworzenia, wstrzymuje program do zakoñczenia tworzenia
void UserDllInterface::makeBoard(Board* board) {

}
//zwraca wspó³rzêdn¹ x strza³u
int UserDllInterface::getShotCoordX() {
	return coordX;
}
//zwraca wspó³rzêdn¹ y strza³u
int UserDllInterface::getShotCoordY() {
	return coordY;
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
	return flagMakeBoard;
}
//sprawdza mo¿liwoœæ po³o¿enia statku o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
bool UserDllInterface::checkShipPlacement(int shipSize, int x, int y, char direction) {
	return false;
}
//umieszcza statkek o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
bool UserDllInterface::placeShip(int shipSize, int x, int y, char direction) {
	return false;
}
//zeruje flagê MakeBoard (plansza jest utworzona)
void UserDllInterface::resetFlagMakeBoard() {
	flagMakeBoard = false;
}
//sprawdza czy ustawiona jest flaga ShootCoors (¿¹danie przekazania wspó³rzêdnych strza³u)
bool UserDllInterface::checkFlagShootCoords() {
	return flagShootCoords;
}
//ustawia wspó³rzêdn¹ x strza³u
void UserDllInterface::setShotCoordX(int x) {
	coordX = x;
}
//ustawia wspó³rzêdn¹ Y strza³u
void UserDllInterface::setShotCoordY(int y) {
	coordY = y;
}
//zeruje flagê ShootCoors (wspó³rzêdne strza³u przekazane)
void UserDllInterface::resetFlagShootCoords() {
	flagShootCoords = false;
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
	flagBoardChanged = false;
}
//sprawdza czy ustawiona jest flaga GameEnded (gra zakoñczona); zwraca numer zwyciêzcy
char UserDllInterface::checkFlagGameEnded() {
	return flagGameEnded;
}
#pragma endregion