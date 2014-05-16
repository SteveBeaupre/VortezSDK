#pragma once

#include "Preproc.h"

#include "Windows.h"
#include "stdio.h"

class _EXP_FUNC CThreadLock {
public:
	CThreadLock();
	~CThreadLock();
private:
	CRITICAL_SECTION cs;
public:
	void Lock();
	void Unlock();
};
