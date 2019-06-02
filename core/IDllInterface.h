#pragma once
#include "Point.hpp"

namespace IDllInterface {
	//wskaŸniki na callbacki
	struct CallBacks {
		//pobiera wspó³rzêdne
		Point (__stdcall *out_getCoords)(void);
	};

	extern "C" {
		//uruchamia grê
		__declspec(dllexport) void runProgram();
		//sprawdza mo¿liwoœæ po³o¿enia statku o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
		__declspec(dllexport) bool checkShipPlacement(int shipSize, int x, int y, char direction);
		//umieszcza statkek o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
		__declspec(dllexport) bool placeShip(int shipSize, int x, int y, char direction);
		//pobiera obraz planszy o numerze 'id'
		__declspec(dllexport)int* getBoardImage(int id);
	}
}