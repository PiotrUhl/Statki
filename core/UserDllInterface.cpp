#include "UserDllInterface.h"

#pragma region singleton
UserDllInterface& UserDllInterface::getInstance() {
	static UserDllInterface&& instance = UserDllInterface();
	return instance;
}
#pragma endregion
#pragma region IUserInterface
//przekazuje planszê board do utworzenia, wstrzymuje program do zakoñczenia tworzenia
void UserDllInterface::makeBoard(Board& board) {

}
//zwraca wspó³rzêdn¹ x strza³u
int UserDllInterface::getShotCoordX() {
	return 0;
}
//zwraca wspó³rzêdn¹ y strza³u
int UserDllInterface::getShotCoordY() {
	return 0;
}
//poinformuj interfejs o zmianie na planszy 'id'; waitForRespond wstrzymuje dzia³anie programu do otrzymania odpowiedzi (interfejs odczyta³ zmianê)
void UserDllInterface::boardChanged(int id, bool waitForRespond = false) {

}
//przekazuje informacje o zakoñczeniu gry
void UserDllInterface::gameEnded(char winner) {

}
#pragma endregion
#include "Game.h"
#pragma region IDLLInterface
//uruchamia grê
void UserDllInterface::runProgram() {
	Game game;
	game.run();
}
#pragma endregion