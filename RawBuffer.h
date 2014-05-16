#pragma once

#include "Preproc.h"

#include "Windows.h"
#include "SafeKill.h"

#include "FileIO.h"
#include "FileSystem.h"
#include "CRC32.h"
#include "Encryptor.h"

class _EXP_FUNC CRawBuffer {
public:
	CRawBuffer();
	CRawBuffer(UINT Size);
	~CRawBuffer();
private:
	UINT BufSize;
	BYTE *pBuf;
public:
	bool IsAllocated();
	
	bool Allocate(UINT Size, BOOL EraseBuf = FALSE);
	void Erase();
	void Set(BYTE Val);
	void Free();

	UINT GetSize();
	void Resize(UINT NewSize);
	
	BYTE* GetBuffer(UINT Indx = 0);
	
	DWORD Hash();

	void Encrypt(UINT Key);
	void Decrypt(UINT Key);

	bool LoadFromFile(char *fname);
	bool SaveToFile(char *fname, UINT MaxSize = 0);
};


