#include "UserInterface.h"

void UserInterface::writeOut(int data) {
	while (DLLinterface::getOutFlag() == true);
	DLLinterface::setOutBuffer(data);
	DLLinterface::setOutFlag();
}

int UserInterface::readIn() {
	while (DLLinterface::getInFlag() == false);
	int data = DLLinterface::getInBuffer();
	DLLinterface::resetInFlag();
	return data;
}