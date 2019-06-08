#include "IDllInterface.h"
#include "UserDllInterface.h"

namespace IDllInterface {
	//uruchamia gr�
	void runProgram(InitData init, CallBacks callBacks) {
		UserDllInterface::getInstance().runProgram(init, callBacks);
	}
	//sprawdza mo�liwo�� po�o�enia statku o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
	bool checkShipPlacement(int shipSize, int x, int y, char direction) {
		bool ret = UserDllInterface::getInstance().checkShipPlacement(shipSize, x, y, direction);
		__asm XOR EAX, EAX;
		return ret;
	}
	//umieszcza statkek o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
	bool placeShip(int shipSize, int x, int y, char direction) {
		bool ret = UserDllInterface::getInstance().placeShip(shipSize, x, y, direction);
		__asm XOR EAX, EAX;
		return ret;
	}
}