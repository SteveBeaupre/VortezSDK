#pragma once

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "Preproc.h"

#define CRC32_INIT  0
#define CRC32_FEED  1
#define CRC32_GET   2

class _EXP_FUNC CCRC32 {
public:
	CCRC32();
private:
	DWORD g_crc;
	DWORD tab[256];
	void GenTab();
public:
	DWORD Generate(void *block, DWORD length);
	DWORD Generate(DWORD Op, void *block, DWORD length);
};
