#include "IDllInterface.h"
#include "UserDllInterface.h"

namespace IDllInterface {
	//uruchamia gr�
	void runProgram() {
		UserDllInterface::getInstance().runProgram();
	}
}