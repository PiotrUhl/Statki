#pragma once

namespace IDllInterface {
	//uruchamia gr�
	extern "C" __declspec(dllexport) void runProgram();
	//sprawdza czy ustawiona jest flaga MakeBoard (��danie utworzenia planszy)
	extern "C" __declspec(dllexport) bool checkFlagMakeBoard();
	//sprawdza mo�liwo�� po�o�enia statku o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
	extern "C" __declspec(dllexport) bool checkShipPlacement(int shipSize, int x, int y, char direction);
	//umieszcza statkek o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
	extern "C" __declspec(dllexport) bool placeShip(int shipSize, int x, int y, char direction);
	//ustawia flag� BoardMade (plansza jest utworzona)
	extern "C" __declspec(dllexport) bool setFlagBoardMade();
	//sprawdza czy ustawiona jest flaga GiveCoors (��danie przekazania wsp�rz�dnych strza�u)
	extern "C" __declspec(dllexport) bool checkFlagGiveCoords();
	//ustawia wsp�rz�dn� x strza�u
	extern "C" __declspec(dllexport) int setShotCoordX();
	//ustawia wsp�rz�dn� Y strza�u
	extern "C" __declspec(dllexport) int setShotCoordy();
	//ustawia flag� CoordsGiven (wsp�rz�dne przekazane)
	extern "C" __declspec(dllexport) bool setFlagCoordsGiven();
	//sprawdza czy ustawiona jest flaga BoardChanged (zg�oszeznie zmiany na planszy); zwraca id zmienionej planszy
	extern "C" __declspec(dllexport) int checkFlagBoardChanged();
	//pobiera obraz planszy o numerze 'id'
	extern "C" __declspec(dllexport) int* getBoardImage(int id);
	//resetuje flag� BoardChanged (zg�oszeznie zmiany na planszy)
	extern "C" __declspec(dllexport) void resetFlagBoardChanged();
	//sprawdza czy ustawiona jest flaga GameEnded (gra zako�czona); zwraca numer zwyci�zcy
	extern "C" __declspec(dllexport) char checkFlagGameEnded();
}