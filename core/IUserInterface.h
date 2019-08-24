#pragma once
#include "structs.hpp" //ShipInfo, Point, ShotResult
#include <list> //std::list

class BoardLocal; //BoardLocal

class IUserInterface {
public:
	//wysy�a do interfejsu wiadomo�� o tre�ci 'msg' o typie 'type'; je�eli 'critical' przerywa dzia�anie programu
	virtual void msg(const char* msg, MsgType type, bool critical = true) = 0;
	//przekazuje plansz� 'board' do utworzenia
	virtual void makeBoard(BoardLocal& board) = 0;
	//zwraca wsp�rz�dne strza�u
	virtual Point getShotCoords() = 0;
	//event - ruch gracza 'playerId'
	virtual void event_playerMoved(int playerId) = 0;
	//event - uko�czono tworzenie planszy 'boardId'
	virtual void event_boardCreated(int boardId) = 0;
	//event - gra zako�czona wynikiem 'result'
	virtual void event_gameEnded(int result) = 0;
	//event - rozpocz�to pierwsz� faz� gry - tworzenie plansz
	virtual void out_event_faze1Started() = 0;
	//event - rozpocz�to drug� faz� gry - strzelanie
	virtual void out_event_faze2Started() = 0;
};
