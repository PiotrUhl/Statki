#include "UserDllInterface.h"

UserDllInterface::UserDllInterface() {} //konstruktor
UserDllInterface& UserDllInterface::getInstance() { //pobierz instancje klasy
	static UserDllInterface&& instance = UserDllInterface();
	return instance;
}
#pragma region IUserInterface
//przekazuje plansz� board do utworzenia, wstrzymuje program do zako�czenia tworzenia
void UserDllInterface::makeBoard(Board* board) {

}
//zwraca wsp�rz�dn� x strza�u
int UserDllInterface::getShotCoordX() {
	return coordX;
}
//zwraca wsp�rz�dn� y strza�u
int UserDllInterface::getShotCoordY() {
	return coordY;
}
//poinformuj interfejs o zmianie na planszy 'id'; waitForRespond wstrzymuje dzia�anie programu do otrzymania odpowiedzi (interfejs odczyta� zmian�)
void UserDllInterface::boardChanged(int id, bool waitForRespond = false) {

}
//przekazuje informacje o zako�czeniu gry
void UserDllInterface::gameEnded(char winner) {

}
#pragma endregion
#include "Game.h"
#pragma region IDLLInterface
//uruchamia gr�
void UserDllInterface::runProgram() {
	Game game;
	game.run();
}
//sprawdza czy ustawiona jest flaga MakeBoard (��danie utworzenia planszy)
bool UserDllInterface::checkFlagMakeBoard() {
	return flagMakeBoard;
}
//sprawdza mo�liwo�� po�o�enia statku o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
bool UserDllInterface::checkShipPlacement(int shipSize, int x, int y, char direction) {
	return false;
}
//umieszcza statkek o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
bool UserDllInterface::placeShip(int shipSize, int x, int y, char direction) {
	return false;
}
//zeruje flag� MakeBoard (plansza jest utworzona)
void UserDllInterface::resetFlagMakeBoard() {
	flagMakeBoard = false;
}
//sprawdza czy ustawiona jest flaga ShootCoors (��danie przekazania wsp�rz�dnych strza�u)
bool UserDllInterface::checkFlagShootCoords() {
	return flagShootCoords;
}
//ustawia wsp�rz�dn� x strza�u
void UserDllInterface::setShotCoordX(int x) {
	coordX = x;
}
//ustawia wsp�rz�dn� Y strza�u
void UserDllInterface::setShotCoordY(int y) {
	coordY = y;
}
//zeruje flag� ShootCoors (wsp�rz�dne strza�u przekazane)
void UserDllInterface::resetFlagShootCoords() {
	flagShootCoords = false;
}
//sprawdza czy ustawiona jest flaga BoardChanged (zg�oszeznie zmiany na planszy); zwraca id zmienionej planszy
int UserDllInterface::checkFlagBoardChanged() {
	return 0;
}
//pobiera obraz planszy o numerze 'id'
int* UserDllInterface::getBoardImage(int id) {
	return nullptr;
}
//resetuje flag� BoardChanged (zg�oszeznie zmiany na planszy)
void UserDllInterface::resetFlagBoardChanged() {
	flagBoardChanged = false;
}
//sprawdza czy ustawiona jest flaga GameEnded (gra zako�czona); zwraca numer zwyci�zcy
char UserDllInterface::checkFlagGameEnded() {
	return flagGameEnded;
}
#pragma endregion