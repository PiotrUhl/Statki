#include "IDllInterface.h"
#include "UserDllInterface.h"

namespace IDllInterface {
	//uruchamia grê
	void runProgram() {
		UserDllInterface::getInstance().runProgram();
	}
}