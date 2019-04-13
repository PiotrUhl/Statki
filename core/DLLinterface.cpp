#include "DLLinterface.h"
#include "Game.h"

namespace DLLinterface {
	void runProgram() { //exported
		Game game;
		game.run();
	}
	//wyjœcie
	bool outFlag = false;
	int outBuffer;
	bool getOutFlag() { //exported
		__asm xor eax, eax; //wymuszone zerowanie akumulatora - bez tego dla C# zawsze True
		return outFlag;
	}
	int getOutBuffer() { //exported
		return outBuffer;
	}
	void setOutFlag() {
		outFlag = true;
	}
	void resetOutFlag() { //exported
		outFlag = false;
	}
	void setOutBuffer(int data) {
		outBuffer = data;
	}
	//wejœcie
	bool inFlag = false;
	int inBuffer;
	bool getInFlag() {
		__asm xor eax, eax; //wymuszone zerowanie akumulatora - bez tego dla C# zawsze True
		return inFlag;
	}
	int getInBuffer() {
		return inBuffer;
	}
	void resetInFlag() {
		inFlag = false;
	}
	void setInFlag() {
		inFlag = true;
	}
	void setInBuffer(int data) {
		inBuffer = data;
	}
}