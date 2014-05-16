#pragma once

#pragma comment(lib, "winmm.lib")

#include "Preproc.h"

#include <Windows.h>
#include "Conversion.h"

class _EXP_FUNC CTimer {
public:
	CTimer();
private:
	bool    IsPerfCounterAvailable;
	float   TimeScale;
	__int64 PerfCounterFrequency;
private:
	__int64 LastTime;
	__int64 CurrentTime;
public:
	void  Reset();
	float Tick();
};

class _EXP_FUNC CTimer64 {
public:
	CTimer64();
private:
	bool     IsPerfCounterAvailable;
	double   TimeScale;
	__int64  PerfCounterFrequency;
private:
	__int64 LastTime;
	__int64 CurrentTime;
public:
	void   Reset();
	double Tick();
};

class _EXP_FUNC CGameTimer {
public:
	CGameTimer();
private:
	bool    IsPerfCounterAvailable;
	float   TimeScale;
	__int64 PerfCounterFrequency;
private:
	__int64 LastTime;
	__int64 CurrentTime;
private:
	float FPS;
	float FPS_ElapsedTime;
public:
	void  Reset();
	float Tick();
	float GetFPS();
};

/*class _EXP_FUNC CCycleTimer {
public:
	CCycleTimer();
private:
	UI64 StartCycle;
	UI64 Overhead;
public:
	UI64 GetOverhead();
public:
	void Start();
	UI64 Stop();
};*/

