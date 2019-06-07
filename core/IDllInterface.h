#pragma once
#include "Point.hpp"
#include "Board.h"

namespace IDllInterface {

	//wska�niki na callbacki
	struct CallBacks {
		//pobiera wsp�rz�dne
		Point (__stdcall *out_getCoords)(void);
		//wysy�a do wypisania plansz�
		void (__stdcall *out_sendShipsInfo)(Board::ShipInfo**, int); //todo: add shotMap
	};

	extern "C" {
		//uruchamia gr�, przyjmuje struktur� callBack�w
		__declspec(dllexport) void runProgram(CallBacks);
		//sprawdza mo�liwo�� po�o�enia statku o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
		__declspec(dllexport) bool checkShipPlacement(int shipSize, int x, int y, char direction);
		//umieszcza statkek o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
		__declspec(dllexport) bool placeShip(int shipSize, int x, int y, char direction);
	}
}