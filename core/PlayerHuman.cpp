#include "PlayerHuman.h"
#include "Point.hpp"

//konstruktor
PlayerHuman::PlayerHuman(IUserInterface& _userInterface, int _BOARDSIZE, Board& _myBoard, Board& _otherBoard) : Player(_BOARDSIZE, _myBoard, _otherBoard), userInterface(_userInterface) {}

//destruktor
PlayerHuman::~PlayerHuman() {}

//gracz wykonuje swój ruch (IUserInterface In)
void PlayerHuman::move() {
	Point point = userInterface.getShotCoords(); //wspó³rzêdne strza³u
	ShotResult shotResult;
	//strza³ i obs³uga b³êdów
	try {
		shotResult = otherBoard.shot(point.x, point.y);
	}
	catch (const std::out_of_range &exc) { //przekroczono zakres tablicy
		//Interface - obs³uga b³êdnego zakresu tablicy
	}
	catch (const std::logic_error &exc) { //w dane pole strzelano wczeœniej
		//Interface - obs³uga strza³u w b³êdne pole
	}
	catch (...) {
		//Interface - obs³uga nieoczekiwanego wyj¹tku
	}
	//Interface - przekazanie informacji o wyniku
}