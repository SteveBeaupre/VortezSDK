#pragma once

#pragma comment(lib, "Winmm.lib")

#include "Preproc.h"

#include "Windows.h"
#include "stdio.h"
#include "Bits.h"
#include "Conversion.h"
#include <direct.h>

class _EXP_FUNC CFileManager {
public:
	struct CFileAttribs {
		bool ReadOnly;
		bool Hidden;
		bool System;
		bool Directory;
		bool Archive;
		bool Normal;
		bool Temporary;
		bool SparseFile;
		bool ReparsePoint;
		bool Compressed;
		bool Offline;
		bool NotIndexed;
		bool Encrypted;
		bool IsVirtual;
	};
public:
	bool DoesExist(char *pFileName);
	bool IsInUse(char *pFileName);
	void Copy(char *pSourceFileName, char *pDestFileName, bool FailIfExist);
	void Move(char *pSourceFileName, char *pDestFileName);
	void Rename(char *pOldFileName, char *pNewFileName);
	void Delete(char *pFileName);
	int  SendToRecycleBin(char *pFileName, WORD Flags = 0x0054);

	UINT GetSize(char *pFileName);
	UI64 GetSize64(char *pFileName);
	void GetShortName(char *pLongFileName, char *pShortFileName);

	UINT GetAttributes(char *pFileName, CFileAttribs *pFileAttribs);
	bool SetAttributes(char *pFileName, CFileAttribs *pFileAttribs);
	bool SetAttributes(char *pFileName, UINT Attribs);

	void Open(char *pFileName, char *pParams);
	void OpenURL(char *pURL);
};

class _EXP_FUNC CFolderManager {
private:
	void MergePath(char *pDest, char *p1, char *p2);
public:
	bool Create(char *pFolderName);
	bool CreateTree(char *pFolderName);
	bool Delete(char *pFolderName);
	bool DeleteTree(char *pFolderName, UINT Level = 0);
	void Rename(char *pOldName, char *pNewName);
	void SendToRecycleBin(char *pFileName);
	bool DoesExist(char *pFolderName, bool TreatDriveRootAsFolder = true);
	void GetCurrent(char *pFolderName);
	void SetCurrent(char *pFolderName);
	void GetShortName(char *pLongFileName, char *pShortFileName);
};

class _EXP_FUNC CDriveManager {
private:
	UI64 GetClustersSizeTaken(DWORD NumBytesPerSectors, DWORD NumSectorsPerCluster, DWORD NumClusters);
	bool IsDriveLetterValid(char *Drive);
public:
	bool DoesExist(char Drive);
	UINT GetAvailableDrives();
	void GetAvailableDrives(bool *pDrives);

	UI64 FreeSpace(char Drive);
	UI64 UsedSpace(char Drive);
	UI64 GetSize(char Drive);
	UI64 GetNumSectors(char Drive);
	UINT GetNumBytesPerSector(char Drive);
	
	UINT GetType(char Drive);
	bool IsCDRom(char Drive);
	bool IsHardDriveDevice(char Drive);
	bool IsFlashDriveDevice(char Drive);
	bool IsDriveRemovable(char Drive);
	bool IsRemoteDrive(char Drive);
	bool IsRamDisk(char Drive);
	
	bool Information(char Drive, char *pLabel, char *pSerialNumber, char *pFileSystem);

	void OpenCDRom(char Drive, BOOL bOpenDrive);
};
