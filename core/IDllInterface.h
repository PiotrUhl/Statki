#pragma once
#include "Point.hpp"

struct ShipInfo {
	int size;
	int x;
	int y;
	char direction;
	bool sunk;
};

struct ShipList {
	ShipInfo* tab;
	int size;
};

namespace IDllInterface {
	//wska�niki na callbacki
	struct CallBacks {
		//pobiera wsp�rz�dne
		Point (__stdcall *out_getCoords)(void);
		//wysy�a do wypisania list� statk�w
		void (__stdcall *out_sendShipList)(ShipList);
		//wysy�a do wypisania informacje w kt�re pola na planszy strzelano
		void (__stdcall *out_sendBoardShooted)(bool*);
	};

	extern "C" {
		//uruchamia gr�
		__declspec(dllexport) void runProgram();
		//sprawdza mo�liwo�� po�o�enia statku o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
		__declspec(dllexport) bool checkShipPlacement(int shipSize, int x, int y, char direction);
		//umieszcza statkek o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
		__declspec(dllexport) bool placeShip(int shipSize, int x, int y, char direction);
	}
}