#include "Cheat.h"

void Cheat::ProcessOptions()
{
	while (isRunning) {
		for (CheatOption* option : options) {
			option->Process();
			Sleep(50);
		}
	}

}
