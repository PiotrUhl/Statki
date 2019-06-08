#pragma once
#include "Point.hpp"
#include "Board.h"

namespace IDllInterface {

	//wskaŸniki na callbacki
	struct CallBacks {
		//rejestruje id planszy
		void (__stdcall *out_registerBoard)(int, int);
		//pobiera wspó³rzêdne
		Point (__stdcall *out_getCoords)(void);
		//wysy³a do wypisania informacje o statkach
		void (__stdcall *out_sendShipsInfo)(Board::ShipInfo**, int, int);
		//wysy³a do wypisania obraz planszy
		void (__stdcall *out_sendShotMap)(unsigned char*, int, int);
		//wypisuje na ekranie b³¹d "error'; "critical" przerywa dzia³anie programu
		void (__stdcall *out_error)(const char*, bool);
	};

	extern "C" {
		//uruchamia grê, przyjmuje strukturê callBacków
		__declspec(dllexport) void runProgram(CallBacks);
		//sprawdza mo¿liwoœæ po³o¿enia statku o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
		__declspec(dllexport) bool checkShipPlacement(int shipSize, int x, int y, char direction);
		//umieszcza statkek o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
		__declspec(dllexport) bool placeShip(int shipSize, int x, int y, char direction);
	}
}