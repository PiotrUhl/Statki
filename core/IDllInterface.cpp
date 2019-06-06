#include "IDllInterface.h"
#include "UserDllInterface.h"

namespace IDllInterface {
	//uruchamia gr�
	void runProgram(CallBacks callBacks) {
		UserDllInterface::getInstance().runProgram(callBacks);
	}
	//sprawdza mo�liwo�� po�o�enia statku o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
	bool checkShipPlacement(int shipSize, int x, int y, char direction) {
		return UserDllInterface::getInstance().checkShipPlacement(shipSize, x, y, direction);
	}
	//umieszcza statkek o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
	bool placeShip(int shipSize, int x, int y, char direction) {
		return UserDllInterface::getInstance().placeShip(shipSize, x, y, direction);
	}
	//pobiera obraz planszy o numerze 'id'
	int* getBoardImage(int id) {
		return UserDllInterface::getInstance().getBoardImage(id);
	}
}