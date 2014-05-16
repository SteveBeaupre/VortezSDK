#include "WinVersion.h"

CWinVersion::CWinVersion()
{
	Init();
}

void CWinVersion::Init()
{
	ZeroMemory(&OSversion, sizeof(OSVERSIONINFO));	
	OSversion.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
}

void CWinVersion::GetVer()
{
	Init();
	GetVersionEx(&OSversion);
}

int CWinVersion::CompareVersion(UINT hi, UINT lo)
{
	if(OSversion.dwMajorVersion < hi){
		return -1;
	} else if(OSversion.dwMajorVersion > hi){
		return 1;
	} else {
		if(OSversion.dwMinorVersion < lo){
			return -1;
		} else if(OSversion.dwMinorVersion > lo){
			return 1;
		} else {
			return 0;
		}
	}

	return 0;
}

bool CWinVersion::IsWindows31OrGreater()
{
	return true;
}

bool CWinVersion::IsWindows95OrGreater()
{
	GetVer();

	if(OSversion.dwPlatformId == VER_PLATFORM_WIN32_NT)
		return true;
	
	if(OSversion.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
		return true;
	
	return false;
}

bool CWinVersion::IsWindows98OrGreater()
{
	GetVer();

	if(OSversion.dwPlatformId == VER_PLATFORM_WIN32_NT)
		return true;
	
	if(OSversion.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
		return OSversion.dwMinorVersion >= 10;
	
	return false;
}

bool CWinVersion::IsWindowsMEOrGreater()
{
	GetVer();

	if(OSversion.dwPlatformId == VER_PLATFORM_WIN32_NT)
		return true;
	
	if(OSversion.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
		return OSversion.dwMinorVersion >= 90;
	
	return false;
}

bool CWinVersion::IsWindowsNTOrGreater()
{
	GetVer();

	if(OSversion.dwPlatformId == VER_PLATFORM_WIN32_NT)
		return CompareVersion(4, 0) >= 0;
	
	return false;
}

bool CWinVersion::IsWindows2000OrGreater()
{
	GetVer();

	if(OSversion.dwPlatformId == VER_PLATFORM_WIN32_NT)
		return CompareVersion(5, 0) >= 0;
	
	return false;
}

bool CWinVersion::IsWindowsXPOrGreater()
{
	GetVer();

	if(OSversion.dwPlatformId == VER_PLATFORM_WIN32_NT)
		return CompareVersion(5, 1) >= 0;
	
	return false;
}

bool CWinVersion::IsWindowsVistaOrGreater()
{
	GetVer();

	if(OSversion.dwPlatformId == VER_PLATFORM_WIN32_NT)
		return CompareVersion(6, 0) >= 0;
	
	return false;
}

bool CWinVersion::IsWindows7OrGreater()
{
	GetVer();

	if(OSversion.dwPlatformId == VER_PLATFORM_WIN32_NT)
		return CompareVersion(6, 1) >= 0;
	
	return false;
}

bool CWinVersion::IsWindows8OrGreater()
{
	GetVer();

	if(OSversion.dwPlatformId == VER_PLATFORM_WIN32_NT)
		return CompareVersion(6, 2) >= 0;
	
	return false;
}

bool CWinVersion::IsWindows81OrGreater()
{
	GetVer();

	if(OSversion.dwPlatformId == VER_PLATFORM_WIN32_NT)
		return CompareVersion(6, 3) >= 0;
	
	return false;
}
