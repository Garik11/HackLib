#include "CheatOption.h"
#include "memory_functions.h"
#include "NopPatch.h"
#include "CavePatch.h"
#include <iostream>
bool CheatOption::Enable()
{
	int pid = GetProcessIdByProcessName(m_processName);
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
	if(hProc) {
		for (Patch* p : patches) {
			p->Hack(hProc);
		}
		CloseHandle(hProc);
		return true;
	}
	return false;
}

bool CheatOption::Disable()
{
	int pid = GetProcessIdByProcessName(m_processName);
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
	if (hProc) {
		for (Patch* p : patches) {
			p->Restore(hProc);
		}
		CloseHandle(hProc);
		return true;
	}
	return false;
}

bool CheatOption::KeyPressed()
{
	for (int key : m_keys) {
		if (GetAsyncKeyState(key) != -32768) return false;
		Sleep(10);
	}
	return true;
}

CheatOption* CheatOption::AddNopPatch(LPCWSTR signature, SIZE_T pSize)
{
	patches.push_back(new NopPatch(this, signature, pSize));
	return this;
}

CheatOption* CheatOption::Add—avePatch(LPCWSTR signature, PBYTE pBytes, SIZE_T patchSize)
{
	patches.push_back(new CavePatch(this, signature, pBytes, patchSize));
	return this;
}

void CheatOption::Process()
{
	if (KeyPressed()) {
		if (m_enabled) {
			Disable();
			m_enabled = false;
		}
		else {
			Enable();
			m_enabled = true;
		}
	}
}
