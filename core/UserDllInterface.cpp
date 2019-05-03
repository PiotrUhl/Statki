#include "UserDllInterface.h"

#pragma region singleton
UserDllInterface& UserDllInterface::getInstance() {
	static UserDllInterface&& instance = UserDllInterface();
	return instance;
}
#pragma endregion
#pragma region IUserInterface
//przekazuje plansz� board do utworzenia, wstrzymuje program do zako�czenia tworzenia
void UserDllInterface::makeBoard(Board& board) {

}
//zwraca wsp�rz�dn� x strza�u
int UserDllInterface::getShotCoordX() {
	return 0;
}
//zwraca wsp�rz�dn� y strza�u
int UserDllInterface::getShotCoordY() {
	return 0;
}
//poinformuj interfejs o zmianie na planszy 'id'; waitForRespond wstrzymuje dzia�anie programu do otrzymania odpowiedzi (interfejs odczyta� zmian�)
void UserDllInterface::boardChanged(int id, bool waitForRespond = false) {

}
//przekazuje informacje o zako�czeniu gry
void UserDllInterface::gameEnded(char winner) {

}
#pragma endregion
#include "Game.h"
#pragma region IDLLInterface
//uruchamia gr�
void UserDllInterface::runProgram() {
	Game game;
	game.run();
}
#pragma endregion