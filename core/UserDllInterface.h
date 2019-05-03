#pragma once
#include "IDllInterface.h"
#include "IUserInterface.h"

class UserDllInterface : public IUserInterface/*, public IDllInterface*/ {
//singleton
	static UserDllInterface&& instance; //jedyna instancja klasy
	UserDllInterface(); //konstruktor
	UserDllInterface(const UserDllInterface&) = delete; //konstruktor kopiuj�cy
	UserDllInterface& operator=(const UserDllInterface&) = delete; //kopiuj�cy operator przypisania
public:
	static UserDllInterface& getInstance(); //pobierz instancje klasy
private:
	//flagi
	bool flagMakeBoard; //tworzenie planszy
	bool flagShootCoors; //przekazywanie wsp�rz�dnych strza�u
	bool flagBoardChanged; //nieodczytana zmiana na planszy
	bool flagGameEnded; //gra jest zako�czona
public:
#pragma region IUserInterface	
	//przekazuje plansz� board do utworzenia, wstrzymuje program do zako�czenia tworzenia
	void makeBoard(Board& board) override;
	//zwraca wsp�rz�dn� x strza�u
	int getShotCoordX() override;
	//zwraca wsp�rz�dn� y strza�u
	int getShotCoordY() override;
	//poinformuj interfejs o zmianie na planszy 'id'; waitForRespond wstrzymuje dzia�anie programu do otrzymania odpowiedzi (interfejs odczyta� zmian�)
	void boardChanged(int id, bool waitForRespond) override;
	//przekazuje informacje o zako�czeniu gry
	void gameEnded(char winner) override;
#pragma endregion
#pragma region IDLLInterface
	//uruchamia gr�
	void runProgram();
	//sprawdza czy ustawiona jest flaga MakeBoard (��danie utworzenia planszy)
	bool checkFlagMakeBoard();
	//sprawdza mo�liwo�� po�o�enia statku o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
	bool checkShipPlacement(int shipSize, int x, int y, char direction);
	//umieszcza statkek o rozmiarze "shipSize" w polu o wsp�rz�dnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
	bool placeShip(int shipSize, int x, int y, char direction);
	//zeruje flag� MakeBoard (plansza jest utworzona)
	void resetFlagMakeBoard();
	//sprawdza czy ustawiona jest flaga ShootCoors (��danie przekazania wsp�rz�dnych strza�u)
	bool checkFlagShootCoords();
	//ustawia wsp�rz�dn� x strza�u
	int setShotCoordX();
	//ustawia wsp�rz�dn� Y strza�u
	int setShotCoordy();
	//zeruje flag� ShootCoors (wsp�rz�dne strza�u przekazane)
	void resetFlagShootCoors();
	//sprawdza czy ustawiona jest flaga BoardChanged (zg�oszeznie zmiany na planszy); zwraca id zmienionej planszy
	int checkFlagBoardChanged();
	//pobiera obraz planszy o numerze 'id'
	int* getBoardImage(int id);
	//resetuje flag� BoardChanged (zg�oszeznie zmiany na planszy)
	void resetFlagBoardChanged();
	//sprawdza czy ustawiona jest flaga GameEnded (gra zako�czona); zwraca numer zwyci�zcy
	char checkFlagGameEnded();
#pragma endregion
};