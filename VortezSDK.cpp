#include "VortezSDK.h"

#ifdef COMPILE_AS_DLL
//-----------------------------------------------------------------------------
// Name : DllMain() (DllMain Entry Point)
//-----------------------------------------------------------------------------
BOOL WINAPI DllMain(HINSTANCE hInst, DWORD fdwreason,  LPVOID lpReserved )
{
	UNREFERENCED_PARAMETER(hInst);
	UNREFERENCED_PARAMETER(lpReserved);
    
	switch(fdwreason)
	{
    case DLL_PROCESS_ATTACH: break;
    case DLL_PROCESS_DETACH: break;
    case DLL_THREAD_ATTACH:  break;
    case DLL_THREAD_DETACH:  break;
    }
    return TRUE;
}
#endif
