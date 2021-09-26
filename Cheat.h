#pragma once
#include <string>
#include <vector>
#include <windows.h>
#include "memory_functions.h"
#include "CheatOption.h"
using namespace std;

class Cheat {
	vector <CheatOption*> options;

	static DWORD WINAPI ProcessorStarter(void* param) {
		Cheat* that = reinterpret_cast<Cheat*>(param);
		that->ProcessOptions();
		return 0;
	}

	bool isRunning = false;

	void ProcessOptions();

public:
	void Start() {
		if (!isRunning) {
			isRunning = true;
			DWORD threadId;
			CreateThread(NULL, 0, ProcessorStarter, this, NULL, &threadId);
		}
	}
	void Stop() { isRunning = false; }

	int AddCheatOption(CheatOption* option) { options.push_back(option); return options.size() - 1; }
	void RemoveCheatOption(int index) { options.erase(options.begin() + index); }
};