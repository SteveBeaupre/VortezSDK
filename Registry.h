#pragma once

#include "Windows.h"
#include "Stdio.h"

#include "Preproc.h"

class _EXP_FUNC CRegistry {
private:
	bool OpenKey(HKEY MainKey, LPCSTR SubKey, HKEY *pKey);
	void CloseKey(HKEY hKey);
public:
	void CreateKey(HKEY MainKey, LPCSTR SubKey);
	void DeleteKey(HKEY MainKey, LPCSTR SubKey);
	bool DoesKeyExist(HKEY MainKey, LPCSTR SubKey);
	
	bool GetValue(HKEY MainKey, LPCSTR SubKey, LPCSTR Value, DWORD Type, void *pBuffer, DWORD *pBufferSize);
	UINT GetValueType(HKEY MainKey, LPCSTR SubKey, LPCSTR Value);
	void SetValue(HKEY MainKey, LPCSTR SubKey, LPCSTR Value, DWORD Type, void *pBuffer, DWORD BufferSize);
	void DeleteValue(HKEY MainKey, LPCSTR SubKey, LPCSTR Value);
	bool DoesValueExist(HKEY MainKey, LPCSTR SubKey, LPCSTR Value);
	
	//GetKeysNames(HKEY MainKey, LPCSTR SubKey); <-- besoin de qqch comme tstringlist
	//GetValueNames(HKEY MainKey, LPCSTR SubKey);<-- besoin de qqch comme tstringlist

	bool LoadInteger(HKEY MainKey, LPCSTR SubKey, LPCSTR Value, void *pBuffer, DWORD DefaultValue = 0);
	void SaveInteger(HKEY MainKey, LPCSTR SubKey, LPCSTR Value, void *pBuffer);
	bool LoadString(HKEY MainKey, LPCSTR SubKey, LPCSTR Value, void *pBuffer, int BufSize, char *pDefaultValue = NULL);
	void SaveString(HKEY MainKey, LPCSTR SubKey, LPCSTR Value, void *pBuffer, int BufSize);
};
