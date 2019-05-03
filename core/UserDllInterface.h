#pragma once
#include "IDllInterface.h"
#include "IUserInterface.h"

class UserDllInterface : public IUserInterface/*, public IDllInterface*/ {
//singleton
	static UserDllInterface&& instance; //jedyna instancja klasy
	UserDllInterface(); //konstruktor
	UserDllInterface(const UserDllInterface&) = delete; //konstruktor kopiuj¹cy
	UserDllInterface& operator=(const UserDllInterface&) = delete; //kopiuj¹cy operator przypisania
public:
	static UserDllInterface& getInstance(); //pobierz instancje klasy
private:
	//flagi
	bool flagMakeBoard; //tworzenie planszy
	bool flagShootCoors; //przekazywanie wspó³rzêdnych strza³u
	bool flagBoardChanged; //nieodczytana zmiana na planszy
	bool flagGameEnded; //gra jest zakoñczona
public:
#pragma region IUserInterface	
	//przekazuje planszê board do utworzenia, wstrzymuje program do zakoñczenia tworzenia
	void makeBoard(Board& board) override;
	//zwraca wspó³rzêdn¹ x strza³u
	int getShotCoordX() override;
	//zwraca wspó³rzêdn¹ y strza³u
	int getShotCoordY() override;
	//poinformuj interfejs o zmianie na planszy 'id'; waitForRespond wstrzymuje dzia³anie programu do otrzymania odpowiedzi (interfejs odczyta³ zmianê)
	void boardChanged(int id, bool waitForRespond) override;
	//przekazuje informacje o zakoñczeniu gry
	void gameEnded(char winner) override;
#pragma endregion
#pragma region IDLLInterface
	//uruchamia grê
	void runProgram();
	//sprawdza czy ustawiona jest flaga MakeBoard (¿¹danie utworzenia planszy)
	bool checkFlagMakeBoard();
	//sprawdza mo¿liwoœæ po³o¿enia statku o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
	bool checkShipPlacement(int shipSize, int x, int y, char direction);
	//umieszcza statkek o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
	bool placeShip(int shipSize, int x, int y, char direction);
	//zeruje flagê MakeBoard (plansza jest utworzona)
	void resetFlagMakeBoard();
	//sprawdza czy ustawiona jest flaga ShootCoors (¿¹danie przekazania wspó³rzêdnych strza³u)
	bool checkFlagShootCoords();
	//ustawia wspó³rzêdn¹ x strza³u
	int setShotCoordX();
	//ustawia wspó³rzêdn¹ Y strza³u
	int setShotCoordy();
	//zeruje flagê ShootCoors (wspó³rzêdne strza³u przekazane)
	void resetFlagShootCoors();
	//sprawdza czy ustawiona jest flaga BoardChanged (zg³oszeznie zmiany na planszy); zwraca id zmienionej planszy
	int checkFlagBoardChanged();
	//pobiera obraz planszy o numerze 'id'
	int* getBoardImage(int id);
	//resetuje flagê BoardChanged (zg³oszeznie zmiany na planszy)
	void resetFlagBoardChanged();
	//sprawdza czy ustawiona jest flaga GameEnded (gra zakoñczona); zwraca numer zwyciêzcy
	char checkFlagGameEnded();
#pragma endregion
};