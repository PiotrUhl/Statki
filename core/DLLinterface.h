#pragma once

namespace DLLinterface {
	//wyj�cie
	extern "C" __declspec(dllexport) bool getOutFlag();
	extern "C" __declspec(dllexport) int getOutBuffer();
	void setOutFlag();
	extern "C" __declspec(dllexport) void resetOutFlag();
	extern "C" __declspec(dllexport) void runProgram();
	void setOutBuffer(int data);
	//wej�cie
	bool getInFlag();
	int getInBuffer();
	void resetInFlag();
	void setInFlag();
	void setInBuffer(int data);
}