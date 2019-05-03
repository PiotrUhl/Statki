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
	//ustawia flagê BoardMade (plansza jest utworzona)
	bool setFlagBoardMade() {
		return UserDllInterface::getInstance().setFlagBoardMade();
	}
	//sprawdza czy ustawiona jest flaga GiveCoors (¿¹danie przekazania wspó³rzêdnych strza³u)
	bool checkFlagGiveCoords() {
		return UserDllInterface::getInstance().checkFlagGiveCoords();
	}
	//ustawia wspó³rzêdn¹ x strza³u
	int setShotCoordX() {
		return UserDllInterface::getInstance().setShotCoordX();
	}
	//ustawia wspó³rzêdn¹ Y strza³u
	int setShotCoordy() {
		return UserDllInterface::getInstance().setShotCoordy();
	}
	//ustawia flagê CoordsGiven (wspó³rzêdne przekazane)
	bool setFlagCoordsGiven() {
		return UserDllInterface::getInstance().setFlagCoordsGiven();
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