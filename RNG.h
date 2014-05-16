#pragma once

#include "Windows.h"

#include "Preproc.h"

#define MT_SIZE  624

class _EXP_FUNC CRNG {
public:
	CRNG();
	CRNG(UINT n);
private:
	int  Index;
	int  MT[MT_SIZE]; 
	void GenMT();
public:
	void Seed(UINT n);
	UINT Rand(UINT Range = 0);
};






 
