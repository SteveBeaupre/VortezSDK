#pragma once

#include "Preproc.h"

#include <Windows.h>
#include <stdio.h>

#define ABORT_IF_RUNNING  0 // Dont start another thread if one is already running
#define WAIT_IF_RUNNING   1 // Wait for the other thread to finish before staring a new one
#define WAIT_FOR_FINISH   2 // Start a new thread and block the calling thread until finish (this one cause the thread handles to be overwriten, rendering further call effective only on the last started thread)

//----------------------------------------------------------------------//
//-----------------------CThread Class Definition-----------------------//
//----------------------------------------------------------------------//

class _EXP_FUNC CThread { 
public:
	CThread(); // No destructor == make sure to call WaitForThread() before closing 
	~CThread();
private:
	DWORD  dwThreadID;
	HANDLE hThread;
	HANDLE hStopThreadEvent;
	HANDLE hPauseThreadEvent;
	void Init();
public:
	HANDLE GetThreadHandle(){return hThread;}
public:
	bool StartThread(LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, UINT WaitMode = ABORT_IF_RUNNING);
	void StopThread();      // Trigger the abort signal, see MustExitThread() below

	bool IsThreadRunning(); // Tell if the thread is running
	void WaitForThread();   // Wait for the thread to finish, blocking the current one (call before closing the program)
	
	bool MustExitThread();  // Call this inside your thread function (periodically, in a loop) to know if the thread should return and terminate now

	void PauseThread();
	void ResumeThread();
	bool IsThreadPaused();
};
