#pragma once
#include "structs.hpp"
#include "Board.h"

namespace IDllInterface {

	//wska�niki na callbacki
	struct CallBacks {
		//pobiera wsp�rz�dne
		Point(__stdcall *out_getCoords)(void);
		//wysy�a do wypisania informacje o statkach
		void(__stdcall *out_sendShipsInfo)(ShipInfo**, int, int);
		//wysy�a do wypisania obraz planszy
		void(__stdcall *out_sendShotMap)(unsigned char*, int, int);
		//wypisuje na ekranie b��d "error'; "critical" przerywa dzia�anie programu
		void(__stdcall *out_error)(const char*, bool);
		//wypisuje na ekranie b��d "error'; "critical" przerywa dzia�anie programu
		void(__stdcall *out_plannerMode)(void);
		//zg�asza do interfejsu wyniki strza�u
		void(__stdcall *out_sendShotInfo)(int, Point, ShotResult);
	};

	extern "C" {
		//uruchamia gr�, przyjmuje struktur� callBack�w
		__declspec(dllexport) void runProgram(InitData, CallBacks);
		//sprawdza mo�liwo�� po�o�enia statku o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
		__declspec(dllexport) bool checkShipPlacement(int shipSize, int x, int y, char direction);
		//umieszcza statkek o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
		__declspec(dllexport) bool placeShip(int shipSize, int x, int y, char direction);
		//wype�nia plansz� losowo u�ywaj�c algorytmu
		__declspec(dllexport) void fillRandom(void);

		//zwraca gracza obecnie wykonuj�cego ruch (b�d� 0 dla niew�a�ciwej cz�ci gry)
		__declspec(dllexport) int getCurrentPlayer();
		//zwraca typ gracza 'playerId' b�d� NONE w przypadku niew�a�ciwego gracza
		__declspec(dllexport) PlayerType getPlayerType(int playerId);
		//zwraca id planszy w kt�r� strzelono jako ostatni� (b�d� 0 je�eli nie strzelano)
		__declspec(dllexport) int getLastShotBoard();
		//zwraca miejsce ostatniego strza�u w plansz� 'boardId'; dla 'boardId' = 0 zwraca miejsce ostatniego strza�u
		__declspec(dllexport) Point getLastShotPoint(int boardId);
		//zwraca wynik ostatniego strza�u w plansz� 'boardId'; dla 'boardId' = 0 zwraca wynik ostatniego strza�u
		__declspec(dllexport) ShotResult getLastShotResult(int boardId);
		//zapisuje obraz planszy 'boardId' do bufora 'outbuffer'
		__declspec(dllexport) void getBoardImage(unsigned char* outbuffer, int boardId);
		//zwraca obraz punktu 'point' na planszy 'boardId'
		__declspec(dllexport) unsigned char getSquareImage(int boardId, Point point);
		//zapisuje map� strza��w planszy 'boardId' do bufora 'outbuffer'
		__declspec(dllexport) void getShotMap(unsigned char* outbuffer, int boardId);
		//zwraca informacj� o strzale w pole 'point' na planszy 'boardId'
		__declspec(dllexport) ShotResult getSquareShot(int boardId, Point point);
		//zwraca informacje o statku le��cym na polu 'point' na planszy 'boardId'
		__declspec(dllexport) ShipInfo getSquareShip(int boardId, Point point);
		//zapisuje informacje o wszystkich statkach na planszy 'boardId' do bufora 'outbuffer'
		__declspec(dllexport) void getShipList(ShipInfo* outbuffer, int boardId);
		//zwraca liczb� statk�w na planszy 'boardId'
		__declspec(dllexport) int getShipCount(int boardId);
	}
}