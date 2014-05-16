#pragma once

#include <Windows.h>

#include "Preproc.h"

class _EXP_FUNC CWinVersion {
public:
	CWinVersion();
private:
	OSVERSIONINFO OSversion;
	
	void Init();
	void GetVer();
	int  CompareVersion(UINT hi, UINT lo);
public:
	bool IsWindows31OrGreater();
	bool IsWindows95OrGreater();
	bool IsWindows98OrGreater();
	bool IsWindowsMEOrGreater();
	bool IsWindows2000OrGreater();
	bool IsWindowsNTOrGreater();
	bool IsWindowsXPOrGreater();
	bool IsWindowsVistaOrGreater();
	bool IsWindows7OrGreater();
	bool IsWindows8OrGreater();
	bool IsWindows81OrGreater();
};
