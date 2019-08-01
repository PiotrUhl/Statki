#include "IDllInterface.h"
#include "UserDllInterface.h"

namespace IDllInterface {
	//uruchamia grê
	void runProgram(InitData init, CallBacks callBacks) {
		UserDllInterface::getInstance().runProgram(init, callBacks);
	}
	//sprawdza mo¿liwoœæ po³o¿enia statku o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
	bool checkShipPlacement(int shipSize, int x, int y, char direction) {
		bool ret = UserDllInterface::getInstance().checkShipPlacement(shipSize, x, y, direction);
		__asm XOR EAX, EAX;
		return ret;
	}
	//umieszcza statkek o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
	bool placeShip(int shipSize, int x, int y, char direction) {
		bool ret = UserDllInterface::getInstance().placeShip(shipSize, x, y, direction);
		__asm XOR EAX, EAX;
		return ret;
	}

	//wype³nia planszê losowo u¿ywaj¹c algorytmu
	void fillRandom() {
		UserDllInterface::getInstance().fillRandom();
	}

	//zwraca gracza obecnie wykonuj¹cego ruch (b¹dŸ 0 dla niew³aœciwej czêœci gry)
	int getCurrentPlayer() {
		return UserDllInterface::getInstance().getCurrentPlayer();
	}

	//zwraca typ gracza 'playerId' b¹dŸ NONE w przypadku niew³aœciwego gracza
	PlayerType getPlayerType(int playerId) {
		return UserDllInterface::getInstance().getPlayerType(playerId);
	}

	//zwraca id planszy w któr¹ strzelono jako ostatni¹ (b¹dŸ 0 je¿eli nie strzelano)
	int getLastShotBoard() {
		return UserDllInterface::getInstance().getLastShotBoard();
	}

	//zwraca miejsce ostatniego strza³u w planszê 'boardId'; dla 'boardId' = 0 zwraca miejsce ostatniego strza³u
	Point getLastShotPoint(int boardId) {
		return UserDllInterface::getInstance().getLastShotPoint(boardId);
	}

	//zwraca wynik ostatniego strza³u w planszê 'boardId'; dla 'boardId' = 0 zwraca wynik ostatniego strza³u
	ShotResult getLastShotResult(int boardId) {
		return UserDllInterface::getInstance().getLastShotResult(boardId);
	}

	//zapisuje obraz planszy 'boardId' do bufora 'outbuffer'
	void getBoardImage(unsigned char* outbuffer, int boardId) {
		return UserDllInterface::getInstance().getBoardImage(outbuffer, boardId);
	}
	//zwraca obraz punktu 'point' na planszy 'boardId'
	unsigned char getSquareImage(int boardId, Point point) {
		return UserDllInterface::getInstance().getSquareImage(boardId, point);
	}

	//zapisuje mapê strza³ów planszy 'boardId' do bufora 'outbuffer'
	void getShotMap(unsigned char* outbuffer, int boardId) {
		UserDllInterface::getInstance().getShotMap(outbuffer, boardId);
	}
	//zwraca informacjê o strzale w pole 'point' na planszy 'boardId'
	ShotResult getSquareShot(int boardId, Point point) {
		return UserDllInterface::getInstance().getSquareShot(boardId, point);
	}

	//zwraca informacje o statku le¿¹cym na polu 'point' na planszy 'boardId'
	ShipInfo getSquareShip(int boardId, Point point) {
		return UserDllInterface::getInstance().getSquareShip(boardId, point);
	}
	//zapisuje informacje o wszystkich statkach na planszy 'boardId' do bufora 'outbuffer'
	void getShipList(ShipInfo* outbuffer, int boardId) {
		UserDllInterface::getInstance().getShipList(outbuffer, boardId);
	}
	//zwraca liczbê statków na planszy 'boardId'
	int getShipCount(int boardId) {
		return UserDllInterface::getInstance().getShipCount(boardId);
	}
}