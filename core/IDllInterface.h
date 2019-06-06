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
	//wskaŸniki na callbacki
	struct CallBacks {
		//pobiera wspó³rzêdne
		Point (__stdcall *out_getCoords)(void);
		//wysy³a do wypisania listê statków
		void (__stdcall *out_sendShipList)(ShipList);
		//wysy³a do wypisania informacje w które pola na planszy strzelano
		void (__stdcall *out_sendBoardShooted)(bool*);
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