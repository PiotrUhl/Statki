#include "UserDllInterface.h"

UserDllInterface::UserDllInterface() {} //konstruktor
UserDllInterface& UserDllInterface::getInstance() { //pobierz instancje klasy
	static UserDllInterface&& instance = UserDllInterface();
	return instance;
}
#pragma region IUserInterface
//przekazuje plansz� board do utworzenia, wstrzymuje program do zako�czenia tworzenia
void UserDllInterface::makeBoard(Board& board) {

}
//zwraca wsp�rz�dn� x strza�u
int UserDllInterface::getShotCoordX() {
	return 0;
}
//zwraca wsp�rz�dn� y strza�u
int UserDllInterface::getShotCoordY() {
	return 0;
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
	return false;
}
//sprawdza mo�liwo�� po�o�enia statku o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
bool UserDllInterface::checkShipPlacement(int shipSize, int x, int y, char direction) {
	return false;
}
//umieszcza statkek o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
bool UserDllInterface::placeShip(int shipSize, int x, int y, char direction) {
	return false;
}
//ustawia flag� BoardMade (plansza jest utworzona)
bool UserDllInterface::setFlagBoardMade() {
	return false;
}
//sprawdza czy ustawiona jest flaga GiveCoors (��danie przekazania wsp�rz�dnych strza�u)
bool UserDllInterface::checkFlagGiveCoords() {
	return false;
}
//ustawia wsp�rz�dn� x strza�u
int UserDllInterface::setShotCoordX() {
	return 0;
}
//ustawia wsp�rz�dn� Y strza�u
int UserDllInterface::setShotCoordy() {
	return 0;
}
//ustawia flag� CoordsGiven (wsp�rz�dne przekazane)
bool UserDllInterface::setFlagCoordsGiven() {
	return false;
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

}
//sprawdza czy ustawiona jest flaga GameEnded (gra zako�czona); zwraca numer zwyci�zcy
char UserDllInterface::checkFlagGameEnded() {
	return 0;
}
#pragma endregion