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
		//zwraca typ gracza 'playerId' b¹dŸ NONE w przypadku niew³aœciwego gracza
		__declspec(dllexport) PlayerType getPlayerType(int playerId);
		//zwraca id planszy w któr¹ strzelono jako ostatni¹ (b¹dŸ 0 je¿eli nie strzelano)
		__declspec(dllexport) int getLastShotBoard();
		//zwraca miejsce ostatniego strza³u w planszê 'boardId'; dla 'boardId' = 0 zwraca miejsce ostatniego strza³u
		__declspec(dllexport) Point getLastShotPoint(int boardId);
		//zwraca wynik ostatniego strza³u w planszê 'boardId'; dla 'boardId' = 0 zwraca wynik ostatniego strza³u
		__declspec(dllexport) ShotResult getLastShotResult(int boardId);
		//zapisuje obraz planszy 'boardId' do bufora 'outbuffer'
		__declspec(dllexport) void getBoardImage(unsigned char* outbuffer, int boardId);
		//zwraca obraz punktu 'point' na planszy 'boardId'
		__declspec(dllexport) unsigned char getSquareImage(int boardId, Point point);
		//zapisuje mapê strza³ów planszy 'boardId' do bufora 'outbuffer'
		__declspec(dllexport) void getShotMap(unsigned char* outbuffer, int boardId);
		//zwraca informacjê o strzale w pole 'point' na planszy 'boardId'
		__declspec(dllexport) ShotResult getSquareShot(int boardId, Point point);
		//zwraca informacje o statku le¿¹cym na polu 'point' na planszy 'boardId'
		__declspec(dllexport) ShipInfo getSquareShip(int boardId, Point point);
		//zapisuje informacje o wszystkich statkach na planszy 'boardId' do bufora 'outbuffer'
		__declspec(dllexport) void getShipList(ShipInfo* outbuffer, int boardId);
	}
}