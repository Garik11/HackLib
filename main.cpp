#include <iostream>
#include <windows.h>
#include "Cheat.h"
using namespace std;

int main(){
	Cheat* cheat = new Cheat();

	vector <int> option1Keys = {VK_CONTROL, 0x4a};
	CheatOption* option1 = new CheatOption(L"Tutorial-i386.exe", NULL, L"SimpleDiscription", option1Keys);
	option1->AddNopPatch(L"29 83 AC 04 00 00", 6);

	vector <int> option2Keys = { VK_CONTROL, 0x4B };
	CheatOption* option2 = new CheatOption(L"Tutorial-i386.exe", NULL, L"SimpleDiscription", option2Keys);
	BYTE  bytes[] = { 0xC7, 0x83, 0xAC, 0x04, 0x00, 0x00, 0x64, 0x00, 0x00, 0x00 };
	option2->AddÑavePatch(L"81 BB AC 04 00 00 E8 03 00 00", bytes, 10);

	cheat->AddCheatOption(option1);
	cheat->AddCheatOption(option2);

	cheat->Start();
	MessageBox(NULL, L"Cheat is running!", L"Cheat", MB_OK);
	cheat->Stop();

	delete option1;
	delete cheat;

	return 0;
}

/*
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

*/