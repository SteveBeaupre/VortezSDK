#include "ThreadLock.h"

CThreadLock::CThreadLock()
{
	InitializeCriticalSection(&cs);
}

CThreadLock::~CThreadLock()
{
	DeleteCriticalSection(&cs);
}

void CThreadLock::Lock()
{
	EnterCriticalSection(&cs);
}

void CThreadLock::Unlock()
{
	LeaveCriticalSection(&cs);
}


