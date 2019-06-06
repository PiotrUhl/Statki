#pragma once
#include "Point.hpp"
#include "Board.h"

namespace IDllInterface {

	struct BoardInfo {
		Board::ShipInfo* tab;
		int size;
		bool** shotMap;
	};

	//wskaŸniki na callbacki
	struct CallBacks {
		//pobiera wspó³rzêdne
		Point (__stdcall *out_getCoords)(void);
		//wysy³a do wypisania planszê
		void (__stdcall *out_sendBoardInfo)(BoardInfo);
	};

	extern "C" {
		//uruchamia grê
		__declspec(dllexport) void runProgram();
		//sprawdza mo¿liwoœæ po³o¿enia statku o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
		__declspec(dllexport) bool checkShipPlacement(int shipSize, int x, int y, char direction);
		//umieszcza statkek o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
		__declspec(dllexport) bool placeShip(int shipSize, int x, int y, char direction);
	}
}