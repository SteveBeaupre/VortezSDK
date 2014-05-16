#pragma once

#include "Windows.h"
#include "stdio.h"
#include "SafeKill.h"

#include <cmath>

#include "Preproc.h"

class _EXP_FUNC CSieveOfAtkin {
public:
	CSieveOfAtkin();
	CSieveOfAtkin(int range);
	~CSieveOfAtkin();
private:
	int  limit;
	bool *sieve;
public:
	void GenSieve(int range);
	void DelSieve();
	
	bool IsPrime(int n);
};