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
	//poinformuj interfejs o zmianie na planszy
	virtual void boardChanged(int, std::list<ShipInfo>, boost::multi_array<ShotResult, 2>) = 0;
	//przekazuje informacje o zako�czeniu gry
	virtual void gameEnded(char winner) = 0;
	//zg�asza do interfejsu wyniki strza�u
	virtual void sendShotInfo(int, Point, ShotResult) = 0;
};
