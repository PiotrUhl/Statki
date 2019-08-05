#pragma once
#include "IDllInterface.h"
#include "IUserInterface.h"
#include "Board.h"
#include "Game.h"
#include "structs.hpp"

class PlannerLocal; //PlannelLocal

class UserDllInterface : public IUserInterface/*, public IDllInterface*/ {
#pragma region singleton
	static UserDllInterface&& instance; //jedyna instancja klasy
	UserDllInterface(); //konstruktor
	UserDllInterface(const UserDllInterface&) = delete; //konstruktor kopiuj¹cy
	UserDllInterface& operator=(const UserDllInterface&) = delete; //kopiuj¹cy operator przypisania
public:
	static UserDllInterface& getInstance(); //pobierz instancje klasy
#pragma endregion
private:
	std::unique_ptr<Game> game; //g³ówna klasa gry
	std::unique_ptr<PlannerLocal> currentPlanner; //uchwyt na obecnie wybrany planer //dla PlannerLocal dla CreatorBoard dla PlayerType::HUMAN
	IDllInterface::CallBacks callBack; //struktura wskaŸników na callBacki
public:
#pragma region IUserInterface	
	//wysy³a do interfejsu wiadomoœæ o treœci 'msg' o typie 'type'; je¿eli 'critical' przerywa dzia³anie programu
	void msg(const char* msg, MsgType type, bool critical = true) override;
	//przekazuje planszê 'board' do utworzenia
	void makeBoard(BoardLocal& board) override;
	//pobiera wspó³rzêdne strza³u
	Point getShotCoords() override;
	//event - ruch gracza 'playerId'
	void event_playerMoved(int playerId) override;
	//event - ukoñczono tworzenie planszy 'boardId'
	void event_boardCreated(int boardId) override;
#pragma endregion
#pragma region IDLLInterface
	//uruchamia grê
	void runProgram(InitData, IDllInterface::CallBacks);
	//sprawdza mo¿liwoœæ po³o¿enia statku o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
	bool checkShipPlacement(int shipSize, int x, int y, char direction);
	//umieszcza statkek o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
	bool placeShip(int shipSize, int x, int y, char direction);
	//wype³nia planszê losowo u¿ywaj¹c algorytmu
	void fillRandom();

	//zwraca gracza obecnie wykonuj¹cego ruch (b¹dŸ 0 dla niew³aœciwej czêœci gry)
	int getCurrentPlayer() const;
	//zwraca typ gracza 'playerId' b¹dŸ NONE w przypadku niew³aœciwego gracza
	PlayerType getPlayerType(int playerId) const;
	//zwraca id planszy w któr¹ strzelono jako ostatni¹ (b¹dŸ 0 je¿eli nie strzelano)
	int getLastShotBoard() const;
	//zwraca miejsce ostatniego strza³u w planszê 'boardId'; dla 'boardId' = 0 zwraca miejsce ostatniego strza³u
	Point getLastShotPoint(int boardId) const;
	//zwraca wynik ostatniego strza³u w planszê 'boardId'; dla 'boardId' = 0 zwraca wynik ostatniego strza³u
	ShotResult getLastShotResult(int boardId) const;
	//zapisuje obraz planszy 'boardId' do bufora 'outbuffer'
	void getBoardImage(unsigned char* outbuffer, int boardId) const;
	//zwraca obraz punktu 'point' na planszy 'boardId'
	unsigned char getSquareImage(int boardId, Point point) const;
	//zapisuje mapê strza³ów planszy 'boardId' do bufora 'outbuffer'
	void getShotMap(unsigned char* outbuffer, int boardId) const;
	//zwraca informacjê o strzale w pole 'point' na planszy 'boardId'
	ShotResult getSquareShot(int boardId, Point point) const;
	//zwraca informacje o statku le¿¹cym na polu 'point' na planszy 'boardId'
	ShipInfo getSquareShip(int boardId, Point point) const;
	//zapisuje informacje o wszystkich statkach na planszy 'boardId' do bufora 'outbuffer'
	void getShipList(ShipInfo* outbuffer, int boardId) const;
	//zwraca liczbê statków na planszy 'boardId'
	int getShipCount(int boardId) const;
#pragma endregion
};