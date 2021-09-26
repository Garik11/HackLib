#include "NopPatch.h"
#include "CheatOption.h"
#define NOP 0x90
bool NopPatch::Hack(HANDLE hProcess)
{
	ULONG scanSize = isTargetX64Process(hProcess) ? 0x7fffffffffffffff : 0x7fffffff;
	DWORD_PTR baseAddress = parent->GetMoubleName() && wcslen(parent->GetMoubleName()) > 0 ?
		GetModuleBaseAddress(hProcess, parent->GetMoubleName()) :
		GetProcessBaseAddress(hProcess);
	originalAddress = ScanSignature(hProcess, baseAddress, scanSize, pattern, mask);
	originalBytes = reinterpret_cast<PBYTE>(ReadMem(hProcess, originalAddress, patchSize));
	PBYTE patchBytes = new BYTE[patchSize];
	memset(patchBytes, 0x90, patchSize);
	WriteMem(hProcess, originalAddress, patchBytes, patchSize);
	delete[] patchBytes;

	return true;
}

bool NopPatch::Restore(HANDLE hProcess)
{
	WriteMem(hProcess, originalAddress, originalBytes, patchSize);
	return false;
}
