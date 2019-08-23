#pragma once
#include "structs.hpp" //ShipInfo, Point, ShotResult
#include <list> //std::list

class BoardLocal; //BoardLocal

class IUserInterface {
public:
	//wysy³a do interfejsu wiadomoœæ o treœci 'msg' o typie 'type'; je¿eli 'critical' przerywa dzia³anie programu
	virtual void msg(const char* msg, MsgType type, bool critical = true) = 0;
	//przekazuje planszê 'board' do utworzenia
	virtual void makeBoard(BoardLocal& board) = 0;
	//zwraca wspó³rzêdne strza³u
	virtual Point getShotCoords() = 0;
	//event - ruch gracza 'playerId'
	virtual void event_playerMoved(int playerId) = 0;
	//event - ukoñczono tworzenie planszy 'boardId'
	virtual void event_boardCreated(int boardId) = 0;
	//event - gra zakoñczona wynikiem 'result'
	virtual void event_gameEnded(int result) = 0;
};
