#pragma once
#include "Point.hpp"
#include "Board.h"

namespace IDllInterface {

	struct BoardInfo {
		Board::ShipInfo* tab;
		int size;
		bool** shotMap;
	};

	//wska�niki na callbacki
	struct CallBacks {
		//pobiera wsp�rz�dne
		Point (__stdcall *out_getCoords)(void);
		//wysy�a do wypisania plansz�
		void (__stdcall *out_sendBoardInfo)(BoardInfo);
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