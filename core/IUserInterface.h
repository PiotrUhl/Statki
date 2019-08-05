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
	//poinformuj interfejs o zmianie na planszy
	virtual void boardChanged(int, std::list<ShipInfo>, boost::multi_array<ShotResult, 2>) = 0;
	//przekazuje informacje o zakoñczeniu gry
	virtual void gameEnded(char winner) = 0;
	//zg³asza do interfejsu wyniki strza³u
	virtual void sendShotInfo(int, Point, ShotResult) = 0;
};
