#include "IDllInterface.h"
#include "UserDllInterface.h"

namespace IDllInterface {
	//uruchamia gr�
	void runProgram() {
		UserDllInterface::getInstance().runProgram();
	}
	//sprawdza czy ustawiona jest flaga MakeBoard (��danie utworzenia planszy)
	bool checkFlagMakeBoard() {
		return UserDllInterface::getInstance().checkFlagMakeBoard();
	}
	//sprawdza mo�liwo�� po�o�enia statku o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
	bool checkShipPlacement(int shipSize, int x, int y, char direction) {
		return UserDllInterface::getInstance().checkShipPlacement(shipSize, x, y, direction);
	}
	//umieszcza statkek o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
	bool placeShip(int shipSize, int x, int y, char direction) {
		return UserDllInterface::getInstance().placeShip(shipSize, x, y, direction);
	}
	//ustawia flag� BoardMade (plansza jest utworzona)
	bool setFlagBoardMade() {
		return UserDllInterface::getInstance().setFlagBoardMade();
	}
	//sprawdza czy ustawiona jest flaga GiveCoors (��danie przekazania wsp�rz�dnych strza�u)
	bool checkFlagGiveCoords() {
		return UserDllInterface::getInstance().checkFlagGiveCoords();
	}
	//ustawia wsp�rz�dn� x strza�u
	int setShotCoordX() {
		return UserDllInterface::getInstance().setShotCoordX();
	}
	//ustawia wsp�rz�dn� Y strza�u
	int setShotCoordy() {
		return UserDllInterface::getInstance().setShotCoordy();
	}
	//ustawia flag� CoordsGiven (wsp�rz�dne przekazane)
	bool setFlagCoordsGiven() {
		return UserDllInterface::getInstance().setFlagCoordsGiven();
	}
	//sprawdza czy ustawiona jest flaga BoardChanged (zg�oszeznie zmiany na planszy); zwraca id zmienionej planszy
	int checkFlagBoardChanged() {
		return UserDllInterface::getInstance().checkFlagBoardChanged();
	}
	//pobiera obraz planszy o numerze 'id'
	int* getBoardImage(int id) {
		return UserDllInterface::getInstance().getBoardImage(id);
	}
	//resetuje flag� BoardChanged (zg�oszeznie zmiany na planszy)
	void resetFlagBoardChanged() {
		UserDllInterface::getInstance().resetFlagBoardChanged();
	}
	//sprawdza czy ustawiona jest flaga GameEnded (gra zako�czona); zwraca numer zwyci�zcy
	char checkFlagGameEnded() {
		return UserDllInterface::getInstance().checkFlagGameEnded();
	}
}