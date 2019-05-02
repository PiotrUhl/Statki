#pragma once
#include "Board.h"
#include <memory>

class Planner {
protected:
	const int BOARDSIZE; //rozmiar planszy
	std::unique_ptr<Board> board; //tworzona plansza
	//sprawdza mo¿liwoœæ po³o¿enia statku o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
public:
	Planner(int _BOARDSIZE); //konstruktor
	~Planner();  //destruktor
	//sprawdza mo¿liwoœæ po³o¿enia statku o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
	bool checkPlacement(int shipSize, int x, int y, char direction);
	//umieszcza statkek o rozmiarze "shipSize" w polu o wspó³rzêdnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
	bool Place(int shipSize, int x, int y, char direction);
	//zwraca obraz tworzonej planszy
	std::shared_ptr<char> getImage();
	//zwraca tworzon¹ planszê
	std::unique_ptr<Board> getBoard();
};