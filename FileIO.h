#pragma once

#include "Preproc.h"

#include <Windows.h>
#include <stdio.h>

#include "Bits.h"
#include "Conversion.h"

class _EXP_FUNC CFileIO {
public:
	CFileIO();
	~CFileIO();
private:
	HANDLE hFile;
public:
	// Open/Create/Close ops.
	bool IsOpened();
	bool OpenForReading(char *fname, bool CanWrite = false);
	bool OpenForWriting(char *fname, bool CanRead = false);
	bool OpenForAppending(char *fname, bool CanRead = false);
	void Close();

	UI64 GetSize();
	void Flush();

	UI64 Tell();
	void Seek(UI64 uiDistanceToMove, DWORD dwMoveMethod = FILE_BEGIN);
	void Seek(LARGE_INTEGER liDistanceToMove, DWORD dwMoveMethod = FILE_BEGIN);

	// Binary buffer Read/Write
	UINT Read(void *pBuffer, UINT NumBytesToRead);
	UINT Write(void *pBuffer, UINT NumBytesToWrite);
};

class _EXP_FUNC CTxtFileIO {
public:
	CTxtFileIO();
	~CTxtFileIO();
private:
	FILE *hFile;
public:
	// Open/Create/Close ops.
	bool IsOpened();
	bool OpenForReading(char *fname, bool CanWrite = false);
	bool OpenForWriting(char *fname, bool CanRead = false);
	bool OpenForAppending(char *fname, bool CanRead = false);
	void Close();

	void Flush();
	UINT Tell();
	void Seek(DWORD DistanceToMove, DWORD MoveMethod = SEEK_SET);
	
	// Text buffer Read/Write
	bool  ReadChar(char *c);
	char* ReadLine(void *pBuffer, UINT BufferSize);
	int   WriteLine(void *pBuffer);
	int   WriteArgs(const char *fmt, ...);

	// Char. Read/Write ops.
	bool WriteChar(char c);
	bool PutBackChar(char c);
};
