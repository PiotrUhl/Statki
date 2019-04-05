#pragma once
#include "DLLinterface.h"

class UserInterface /*: public IUserInterface*/ {
public:
	static void writeOut(int data);
	static int readIn();
};