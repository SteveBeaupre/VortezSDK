#pragma once

#include <Windows.h>
#include "PreProc.h"

bool _EXP_FUNC ReadBit(void *pBitField, DWORD BitIndx, DWORD DataSize = 0);
void _EXP_FUNC WriteBit(void *pBitField, DWORD BitIndx, BYTE BitValue, DWORD DataSize = 0);
