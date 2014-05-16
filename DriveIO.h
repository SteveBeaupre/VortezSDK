#pragma once

#include "Preproc.h"

#include "Windows.h"
#include "stdio.h"
#include "Conversion.h"

class _EXP_FUNC CDriveIO {
public:
	CDriveIO();
private:
	HANDLE hDrive;

	char DriveLetter;
	UI64 CursorPos;

	UI64 NumBytes;
	UI64 NumSectors;
	UI64 SectorSize;
	
	DWORD NumBytesPerSector;
	DWORD NumSectorsPerCluster;
	DWORD NumberOfClusters;

	BOOL (WINAPI * pSetFilePointerEx)(HANDLE hFile, LARGE_INTEGER liDistanceToMove, PLARGE_INTEGER lpNewFilePointer, DWORD dwMoveMethod);

	void LoadSetFilePointerEx();
	bool IsDriveLetterValid(char *Drive);
	void ResetDiskInfo();
	void LoadDriveInformation(char Drive);
	bool IncFilePointerPosition(LARGE_INTEGER DistanceToMove);
public:
	bool IsOpened();
	bool Open(char Drive, bool WriteAccess = false);
	void Close();

	UI64 Tell();
	void Seek(LARGE_INTEGER liDistanceToMove, DWORD dwMoveMethod = FILE_BEGIN);
	void Seek(UI64 uiDistanceToMove, DWORD dwMoveMethod = FILE_BEGIN);

	DWORD ReadBuffer(BYTE *pBuffer, UINT NumBytesToRead);
	DWORD ReadSectors(BYTE *pBuffer, UINT NumSectorsToRead);
	DWORD WriteBuffer(BYTE *pBuffer, UINT NumBytesToWrite);
	DWORD WriteSectors(BYTE *pBuffer, UINT NumSectorsToWrite);

	char GetOpenedDriveLetter();

	UI64 GetSize();
	UI64 GetSectorsCount();

	DWORD GetNumberOfClusters();
	DWORD GetNumBytesPerSector();
	DWORD GetNumSectorsPerCluster();

	UI64 GetNumBytesFree(char Drive);
	UI64 GetNumBytesUsed(char Drive);
	UI64 GetNumSectorFree(char Drive);
	UI64 GetNumSectorUsed(char Drive);
};
