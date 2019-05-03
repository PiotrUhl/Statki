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
	//zeruje flag� MakeBoard (plansza jest utworzona)
	 void resetFlagMakeBoard() {
		UserDllInterface::getInstance().resetFlagMakeBoard();
	}
	 //sprawdza czy ustawiona jest flaga ShootCoors (��danie przekazania wsp�rz�dnych strza�u)
	 bool checkFlagShootCoords() {
		return UserDllInterface::getInstance().checkFlagShootCoords();
	}
	//ustawia wsp�rz�dn� x strza�u
	int setShotCoordX() {
		return UserDllInterface::getInstance().setShotCoordX();
	}
	//ustawia wsp�rz�dn� y strza�u
	int setShotCoordy() {
		return UserDllInterface::getInstance().setShotCoordy();
	}
	//zeruje flag� ShootCoors (wsp�rz�dne strza�u przekazane)
	void resetFlagShootCoors() {
		UserDllInterface::getInstance().resetFlagShootCoors();
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