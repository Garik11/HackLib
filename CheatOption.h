#pragma once
#include <windows.h>
#include <vector>
#include <string>
#include "Patch.h"
using namespace std;

class CheatOption
{
	//Properties
	LPCWSTR m_processName = NULL;
	LPCWSTR m_moduleName = NULL;
	LPCWSTR m_description = NULL;

	//Service fields
	vector <int> m_keys;
	bool m_enabled = false;
	vector <Patch*> patches;

	bool Enable();
	bool Disable();
	bool KeyPressed();

public:
	CheatOption(LPCWSTR processName, LPCWSTR moduleName, LPCWSTR description, const vector<int>& keys) {
		m_processName = processName;
		m_moduleName = moduleName;
		m_description = description;
		m_keys = keys;
		patches.clear();
	}


	CheatOption* AddNopPatch(LPCWSTR signature, SIZE_T pSize);
	CheatOption* Add—avePatch(LPCWSTR signature, PBYTE pBytes, SIZE_T patchSize);

	bool isEnabled() { return m_enabled; }
	void Process();
	LPCWSTR GetDescription() { return m_description; }
	LPCWSTR GetMoubleName() { return m_moduleName; }


};

