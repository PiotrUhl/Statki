#pragma once
#include "Point.hpp"
#include "structs.hpp"
#include "Board.h"

namespace IDllInterface {

	//wskaŸniki na callbacki
	struct CallBacks {
		//rejestruje id planszy
		void(__stdcall *out_registerBoard)(int, int);
		//pobiera wspó³rzêdne
		Point(__stdcall *out_getCoords)(void);
		//wysy³a do wypisania informacje o statkach
		void(__stdcall *out_sendShipsInfo)(ShipInfo**, int, int);
		//wysy³a do wypisania obraz planszy
		void(__stdcall *out_sendShotMap)(unsigned char*, int, int);
		//wypisuje na ekranie b³¹d "error'; "critical" przerywa dzia³anie programu
		void(__stdcall *out_error)(const char*, bool);
		//wypisuje na ekranie b³¹d "error'; "critical" przerywa dzia³anie programu
		void(__stdcall *out_plannerMode)(void);
		//zg³asza do interfejsu wyniki strza³u
		void(__stdcall *out_sendShotInfo)(int, Point, ShotResult);
	};

	extern "C" {
		//uruchamia grê, przyjmuje strukturê callBacków
		__declspec(dllexport) void runProgram(InitData, CallBacks);
		//sprawdza mo¿liwoœæ po³o¿enia statku o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
		__declspec(dllexport) bool checkShipPlacement(int shipSize, int x, int y, char direction);
		//umieszcza statkek o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
		__declspec(dllexport) bool placeShip(int shipSize, int x, int y, char direction);

		//todo: interfejs wyjœciowy
		//zwraca gracza obecnie wykonuj¹cego ruch (b¹dŸ 0 dla niew³aœciwej czêœci gry)
		__declspec(dllexport) int getCurrentPlayer();
		//__declspec(dllexport) PlayerType getPlayerType(int playerId);
		//__declspec(dllexport) Point getLastShotPoint();
		//__declspec(dllexport) ShotResult getLastShotResult();
		//__declspec(dllexport) int getLastShotBoard();
		//__declspec(dllexport) unsigned char* getBoardImage(int boardId);
		//__declspec(dllexport) ShipInfo** getShipList(int boardId);
		//__declspec(dllexport) unsigned char* getShotMap(int boardId);
		//__declspec(dllexport) ShipInfo getSquareShip(int boardId, Point point);
		//__declspec(dllexport) ShotResult getSquareState(int boardId, Point point);
	}
}