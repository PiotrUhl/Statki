#pragma once

class Board; //Board

class IUserInterface {
public:
	//przekazuje planszê board do utworzenia, wstrzymuje program do zakoñczenia tworzenia
	virtual void makeBoard(Board& board) = 0;
	//zwraca wspó³rzêdn¹ x strza³u
	virtual int getShotCoordX() = 0;
	//zwraca wspó³rzêdn¹ y strza³u
	virtual int getShotCoordY() = 0;
	//poinformuj interfejs o zmianie na planszy 'id'; waitForRespond wstrzymuje dzia³anie programu do otrzymania odpowiedzi (interfejs odczyta³ zmianê)
	virtual void boardChanged(int id, bool waitForRespond = false) = 0;
	//przekazuje informacje o zakoñczeniu gry
	virtual void gameEnded(char winner) = 0;
	//wirtualny destruktor
	virtual ~IUserInterface() = 0;
};
