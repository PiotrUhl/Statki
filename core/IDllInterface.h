#pragma once
#include "structs.hpp"
#include "Board.h"

namespace IDllInterface {

	//wskaŸniki na callbacki
	struct CallBacks {
		//wysy³a do interfejsu wiadomoœæ o treœci 'msg' o typie 'type'; je¿eli 'critical' przerywa dzia³anie programu
		void(__stdcall *out_msg)(const char* msg, MsgType type, bool critical);
		//pobiera wspó³rzêdne
		Point (__stdcall *out_getCoords)(void);
		//przechodzi w tryb rêcznego tworzenia planszy
		void(__stdcall *out_enterPlannerMode)(void);

		//event - ruch gracza 'playerId'
		void(__stdcall *out_event_playerMoved)(int playerId);
		//event - ukoñczono tworzenie planszy 'boardId'
		void(__stdcall *out_event_boardCreated)(int boardId);
	};

	extern "C" {
		//uruchamia grê, przyjmuje strukturê callBacków
		__declspec(dllexport) void runProgram(InitData, CallBacks);
		//sprawdza mo¿liwoœæ po³o¿enia statku o rozmiarze "shipSize" w polu 'point', w kierunku direction
		__declspec(dllexport) bool checkShipPlacement(int shipSize, Point point, Direction direction);
		//umieszcza statkek o rozmiarze "shipSize" w polu 'point', w kierunku direction; zwraca rezultat
		__declspec(dllexport) bool placeShip(int shipSize, Point point, Direction direction);
		//wype³nia planszê losowo u¿ywaj¹c algorytmu
		__declspec(dllexport) void fillRandom(void);

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
		//zwraca informacje o statku le¿¹cym na polu 'point' na planszy 'boardId' poprzez parametr 'ret'
		__declspec(dllexport) void getSquareShip(ShipInfo& ret , int boardId, Point point);
		//zapisuje informacje o wszystkich statkach na planszy 'boardId' do bufora 'outbuffer'
		__declspec(dllexport) void getShipList(ShipInfo* outbuffer, int boardId);
		//zwraca liczbê statków na planszy 'boardId'
		__declspec(dllexport) int getShipCount(int boardId);
	}
}