#include "PlayerHuman.h"

//konstruktor
PlayerHuman::PlayerHuman(int _BOARD_SIZE) : Player(_BOARD_SIZE) {}

//destruktor
PlayerHuman::~PlayerHuman() {}

//gracz wykonuje swój ruch (IUserInterface In)
void PlayerHuman::move() {
	int x, y; //wspó³rzêdne strza³u
	//Interface - pobranie wspó³rzêdnych
	x = 0; //temp
	y = 0; //temp
	Player::ShotResult shotResult;
	//strza³ i obs³uga b³êdów
	try {
		shotResult = static_cast<Player::ShotResult>(otherBoard->shot(x, y));
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