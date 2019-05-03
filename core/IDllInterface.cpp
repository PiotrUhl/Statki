#include "IDllInterface.h"
#include "UserDllInterface.h"

namespace IDllInterface {
	//uruchamia grê
	void runProgram() {
		UserDllInterface::getInstance().runProgram();
	}
	//sprawdza czy ustawiona jest flaga MakeBoard (¿¹danie utworzenia planszy)
	bool checkFlagMakeBoard() {
		return UserDllInterface::getInstance().checkFlagMakeBoard();
	}
	//sprawdza mo¿liwoœæ po³o¿enia statku o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
	bool checkShipPlacement(int shipSize, int x, int y, char direction) {
		return UserDllInterface::getInstance().checkShipPlacement(shipSize, x, y, direction);
	}
	//umieszcza statkek o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
	bool placeShip(int shipSize, int x, int y, char direction) {
		return UserDllInterface::getInstance().placeShip(shipSize, x, y, direction);
	}
	//zeruje flagê MakeBoard (plansza jest utworzona)
	 void resetFlagMakeBoard() {
		UserDllInterface::getInstance().resetFlagMakeBoard();
	}
	 //sprawdza czy ustawiona jest flaga ShootCoors (¿¹danie przekazania wspó³rzêdnych strza³u)
	 bool checkFlagShootCoords() {
		return UserDllInterface::getInstance().checkFlagShootCoords();
	}
	//ustawia wspó³rzêdn¹ x strza³u
	int setShotCoordX() {
		return UserDllInterface::getInstance().setShotCoordX();
	}
	//ustawia wspó³rzêdn¹ y strza³u
	int setShotCoordy() {
		return UserDllInterface::getInstance().setShotCoordy();
	}
	//zeruje flagê ShootCoors (wspó³rzêdne strza³u przekazane)
	void resetFlagShootCoors() {
		UserDllInterface::getInstance().resetFlagShootCoors();
	}
	//sprawdza czy ustawiona jest flaga BoardChanged (zg³oszeznie zmiany na planszy); zwraca id zmienionej planszy
	int checkFlagBoardChanged() {
		return UserDllInterface::getInstance().checkFlagBoardChanged();
	}
	//pobiera obraz planszy o numerze 'id'
	int* getBoardImage(int id) {
		return UserDllInterface::getInstance().getBoardImage(id);
	}
	//resetuje flagê BoardChanged (zg³oszeznie zmiany na planszy)
	void resetFlagBoardChanged() {
		UserDllInterface::getInstance().resetFlagBoardChanged();
	}
	//sprawdza czy ustawiona jest flaga GameEnded (gra zakoñczona); zwraca numer zwyciêzcy
	char checkFlagGameEnded() {
		return UserDllInterface::getInstance().checkFlagGameEnded();
	}
}