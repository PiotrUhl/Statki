#include "PlayerHuman.h"
#include "Point.hpp"

//konstruktor
PlayerHuman::PlayerHuman(IUserInterface& _userInterface, int _BOARDSIZE, Board& _myBoard, Board& _otherBoard) : Player(_BOARDSIZE, _myBoard, _otherBoard), userInterface(_userInterface) {}

//destruktor
PlayerHuman::~PlayerHuman() {}

//gracz wykonuje sw�j ruch (IUserInterface In)
void PlayerHuman::move() {
	Point point = userInterface.getShotCoords(); //wsp�rz�dne strza�u
	ShotResult shotResult;
	//strza� i obs�uga b��d�w
	try {
		shotResult = otherBoard.shot(point.x, point.y);
	}
	catch (const std::out_of_range &exc) { //przekroczono zakres tablicy
		//Interface - obs�uga b��dnego zakresu tablicy
	}
	catch (const std::logic_error &exc) { //w dane pole strzelano wcze�niej
		//Interface - obs�uga strza�u w b��dne pole
	}
	catch (...) {
		//Interface - obs�uga nieoczekiwanego wyj�tku
	}
	//Interface - przekazanie informacji o wyniku
}