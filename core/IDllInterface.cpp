#include "IDllInterface.h"
#include "UserDllInterface.h"

namespace IDllInterface {
	//uruchamia gr�
	void runProgram(InitData init, CallBacks callBacks) {
		UserDllInterface::getInstance().runProgram(init, callBacks);
	}
	//sprawdza mo�liwo�� po�o�enia statku o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
	bool checkShipPlacement(int shipSize, int x, int y, char direction) {
		bool ret = UserDllInterface::getInstance().checkShipPlacement(shipSize, x, y, direction);
		__asm XOR EAX, EAX;
		return ret;
	}
	//umieszcza statkek o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
	bool placeShip(int shipSize, int x, int y, char direction) {
		bool ret = UserDllInterface::getInstance().placeShip(shipSize, x, y, direction);
		__asm XOR EAX, EAX;
		return ret;
	}

	//wype�nia plansz� losowo u�ywaj�c algorytmu
	void fillRandom() {
		UserDllInterface::getInstance().fillRandom();
	}

	//zwraca gracza obecnie wykonuj�cego ruch (b�d� 0 dla niew�a�ciwej cz�ci gry)
	int getCurrentPlayer() {
		return UserDllInterface::getInstance().getCurrentPlayer();
	}

	//zwraca typ gracza 'playerId' b�d� NONE w przypadku niew�a�ciwego gracza
	PlayerType getPlayerType(int playerId) {
		return UserDllInterface::getInstance().getPlayerType(playerId);
	}

	//zwraca id planszy w kt�r� strzelono jako ostatni� (b�d� 0 je�eli nie strzelano)
	int getLastShotBoard() {
		return UserDllInterface::getInstance().getLastShotBoard();
	}

	//zwraca miejsce ostatniego strza�u w plansz� 'boardId'; dla 'boardId' = 0 zwraca miejsce ostatniego strza�u
	Point getLastShotPoint(int boardId) {
		return UserDllInterface::getInstance().getLastShotPoint(boardId);
	}

	//zwraca wynik ostatniego strza�u w plansz� 'boardId'; dla 'boardId' = 0 zwraca wynik ostatniego strza�u
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

	//zapisuje map� strza��w planszy 'boardId' do bufora 'outbuffer'
	void getShotMap(unsigned char* outbuffer, int boardId) {
		UserDllInterface::getInstance().getShotMap(outbuffer, boardId);
	}
	//zwraca informacj� o strzale w pole 'point' na planszy 'boardId'
	ShotResult getSquareShot(int boardId, Point point) {
		return UserDllInterface::getInstance().getSquareShot(boardId, point);
	}

	//zwraca informacje o statku le��cym na polu 'point' na planszy 'boardId'
	ShipInfo getSquareShip(int boardId, Point point) {
		return UserDllInterface::getInstance().getSquareShip(boardId, point);
	}
	//zapisuje informacje o wszystkich statkach na planszy 'boardId' do bufora 'outbuffer'
	void getShipList(ShipInfo* outbuffer, int boardId) {
		UserDllInterface::getInstance().getShipList(outbuffer, boardId);
	}
	//zwraca liczb� statk�w na planszy 'boardId'
	int getShipCount(int boardId) {
		return UserDllInterface::getInstance().getShipCount(boardId);
	}
}