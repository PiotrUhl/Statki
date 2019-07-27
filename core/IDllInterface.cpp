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
}