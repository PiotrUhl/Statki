#include "PlayerHuman.h"

//konstruktor
PlayerHuman::PlayerHuman(int _BOARD_SIZE) : Player(_BOARD_SIZE) {}

//destruktor
PlayerHuman::~PlayerHuman() {}

//gracz wykonuje sw�j ruch (IUserInterface In)
void PlayerHuman::move() {
	int x, y; //wsp�rz�dne strza�u
	//Interface - pobranie wsp�rz�dnych
	x = 0; //temp
	y = 0; //temp
	Player::ShotResult shotResult;
	//strza� i obs�uga b��d�w
	try {
		shotResult = static_cast<Player::ShotResult>(otherBoard->shot(x, y));
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