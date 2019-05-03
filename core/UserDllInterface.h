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
#pragma endregion
};