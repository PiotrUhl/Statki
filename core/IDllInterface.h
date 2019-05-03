#pragma once

namespace IDllInterface {
	//uruchamia grê
	extern "C" __declspec(dllexport) void runProgram();
	//sprawdza czy ustawiona jest flaga MakeBoard (¿¹danie utworzenia planszy)
	extern "C" __declspec(dllexport) bool checkFlagMakeBoard();
	//sprawdza mo¿liwoœæ po³o¿enia statku o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
	extern "C" __declspec(dllexport) bool checkShipPlacement(int shipSize, int x, int y, char direction);
	//umieszcza statkek o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
	extern "C" __declspec(dllexport) bool placeShip(int shipSize, int x, int y, char direction);
	//zeruje flagê MakeBoard (plansza jest utworzona)
	extern "C" __declspec(dllexport) void resetFlagMakeBoard();
	//sprawdza czy ustawiona jest flaga ShootCoors (¿¹danie przekazania wspó³rzêdnych strza³u)
	extern "C" __declspec(dllexport) bool checkFlagShootCoords();
	//ustawia wspó³rzêdn¹ x strza³u
	extern "C" __declspec(dllexport) int setShotCoordX();
	//ustawia wspó³rzêdn¹ y strza³u
	extern "C" __declspec(dllexport) int setShotCoordy();
	//zeruje flagê ShootCoors (wspó³rzêdne strza³u przekazane)
	extern "C" __declspec(dllexport) void resetFlagShootCoors();
	//sprawdza czy ustawiona jest flaga BoardChanged (zg³oszeznie zmiany na planszy); zwraca id zmienionej planszy
	extern "C" __declspec(dllexport) int checkFlagBoardChanged();
	//pobiera obraz planszy o numerze 'id'
	extern "C" __declspec(dllexport) int* getBoardImage(int id);
	//resetuje flagê BoardChanged (zg³oszeznie zmiany na planszy)
	extern "C" __declspec(dllexport) void resetFlagBoardChanged();
	//sprawdza czy ustawiona jest flaga GameEnded (gra zakoñczona); zwraca numer zwyciêzcy
	extern "C" __declspec(dllexport) char checkFlagGameEnded();
}