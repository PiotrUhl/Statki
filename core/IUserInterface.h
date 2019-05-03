#pragma once

class Board; //Board

class IUserInterface {
public:
	//przekazuje plansz� board do utworzenia, wstrzymuje program do zako�czenia tworzenia
	virtual void makeBoard(Board& board) = 0;
	//zwraca wsp�rz�dn� x strza�u
	virtual int getShotCoordX() = 0;
	//zwraca wsp�rz�dn� y strza�u
	virtual int getShotCoordY() = 0;
	//poinformuj interfejs o zmianie na planszy 'id'; waitForRespond wstrzymuje dzia�anie programu do otrzymania odpowiedzi (interfejs odczyta� zmian�)
	virtual void boardChanged(int id, bool waitForRespond = false) = 0;
	//przekazuje informacje o zako�czeniu gry
	virtual void gameEnded(char winner) = 0;
	//wirtualny destruktor
	virtual ~IUserInterface() = 0;
};
