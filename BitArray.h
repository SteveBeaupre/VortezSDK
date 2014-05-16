#pragma once

#include <Windows.h>
#include "Bits.h"

#include "Preproc.h"

class _EXP_FUNC CBitArray {
public:
	CBitArray();
	~CBitArray();
private:
	BYTE *pBuffer;
	UINT BitsCount;
	UINT BufferSize;
public:
	bool IsAllocated();
	void Allocate(UINT NumBits);
	void Resize(UINT NumBits);
	void FreeMem();

	void ClearAll();
	void SetAll();

	bool GetBit(UINT Indx);
	void SetBit(UINT Indx, bool Value = true);
	bool operator[](UINT Indx);
};
