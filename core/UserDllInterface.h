#pragma once
#include "IDllInterface.h"
#include "IUserInterface.h"

class UserDllInterface : public IUserInterface/*, public IDllInterface*/ {
#pragma region singleton
	UserDllInterface() = default;
	UserDllInterface(const UserDllInterface&) = delete;
	UserDllInterface& operator=(const UserDllInterface&) = delete;
public:
	static UserDllInterface& getInstance();
private:
#pragma endregion
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
#pragma endregion
};