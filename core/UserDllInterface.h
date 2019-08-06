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
	UserDllInterface(const UserDllInterface&) = delete; //konstruktor kopiuj�cy
	UserDllInterface& operator=(const UserDllInterface&) = delete; //kopiuj�cy operator przypisania
public:
	static UserDllInterface& getInstance(); //pobierz instancje klasy
#pragma endregion
private:
	std::unique_ptr<Game> game; //g��wna klasa gry
	std::unique_ptr<PlannerLocal> currentPlanner; //uchwyt na obecnie wybrany planer //dla PlannerLocal dla CreatorBoard dla PlayerType::HUMAN
	IDllInterface::CallBacks callBack; //struktura wska�nik�w na callBacki
public:
#pragma region IUserInterface	
	//wysy�a do interfejsu wiadomo�� o tre�ci 'msg' o typie 'type'; je�eli 'critical' przerywa dzia�anie programu
	void msg(const char* msg, MsgType type, bool critical = true) override;
	//przekazuje plansz� 'board' do utworzenia
	void makeBoard(BoardLocal& board) override;
	//pobiera wsp�rz�dne strza�u
	Point getShotCoords() override;
	//event - ruch gracza 'playerId'
	void event_playerMoved(int playerId) override;
	//event - uko�czono tworzenie planszy 'boardId'
	void event_boardCreated(int boardId) override;
#pragma endregion
#pragma region IDLLInterface
	//uruchamia gr�
	void runProgram(InitData, IDllInterface::CallBacks);
	//sprawdza mo�liwo�� po�o�enia statku o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
	bool checkShipPlacement(int shipSize, int x, int y, char direction);
	//umieszcza statkek o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
	bool placeShip(int shipSize, int x, int y, char direction);
	//wype�nia plansz� losowo u�ywaj�c algorytmu
	void fillRandom();

	//zwraca gracza obecnie wykonuj�cego ruch (b�d� 0 dla niew�a�ciwej cz�ci gry)
	int getCurrentPlayer() const;
	//zwraca typ gracza 'playerId' b�d� NONE w przypadku niew�a�ciwego gracza
	PlayerType getPlayerType(int playerId) const;
	//zwraca id planszy w kt�r� strzelono jako ostatni� (b�d� 0 je�eli nie strzelano)
	int getLastShotBoard() const;
	//zwraca miejsce ostatniego strza�u w plansz� 'boardId'; dla 'boardId' = 0 zwraca miejsce ostatniego strza�u
	Point getLastShotPoint(int boardId) const;
	//zwraca wynik ostatniego strza�u w plansz� 'boardId'; dla 'boardId' = 0 zwraca wynik ostatniego strza�u
	ShotResult getLastShotResult(int boardId) const;
	//zapisuje obraz planszy 'boardId' do bufora 'outbuffer'
	void getBoardImage(unsigned char* outbuffer, int boardId) const;
	//zwraca obraz punktu 'point' na planszy 'boardId'
	unsigned char getSquareImage(int boardId, Point point) const;
	//zapisuje map� strza��w planszy 'boardId' do bufora 'outbuffer'
	void getShotMap(unsigned char* outbuffer, int boardId) const;
	//zwraca informacj� o strzale w pole 'point' na planszy 'boardId'
	ShotResult getSquareShot(int boardId, Point point) const;
	//zwraca informacje o statku le��cym na polu 'point' na planszy 'boardId'
	ShipInfo getSquareShip(int boardId, Point point) const;
	//zapisuje informacje o wszystkich statkach na planszy 'boardId' do bufora 'outbuffer'
	void getShipList(ShipInfo* outbuffer, int boardId) const;
	//zwraca liczb� statk�w na planszy 'boardId'
	int getShipCount(int boardId) const;
#pragma endregion
};