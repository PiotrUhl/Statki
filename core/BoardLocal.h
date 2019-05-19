#pragma once
#include "Board.h"
#include "Square.h"
#include <vector>

class BoardLocal : public Board {
private:
	std::vector<std::vector<Square>> board; //plansza
public:
	//konstruktor
	BoardLocal(int _BOARD_SIZE);
	//destruktor
	~BoardLocal();
	//przeci¹¿ony operator []
	std::vector<Square>& operator[](int);
	//umieszcza statkek o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
	bool placeShip(int shipSize, int x, int y, char direction);
	//usuwa statkek z pola ("x", "y")
	bool removeShip(int x, int y);
	//zwraca obraz planszy
	std::shared_ptr<char> getImage();
	//strzela w pole planszy o wspó³rzêdnych (x, y); zwraca rezultat
	ShotResult shot(int x, int y) override;
	//usuwa ca³¹ zawartoœæ planszy
	void clear();
};
//todo: getImage();