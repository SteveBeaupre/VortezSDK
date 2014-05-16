#include "RNG.h"

CRNG::CRNG()
{
	Seed(0);
}

CRNG::CRNG(UINT n)
{
	Seed(n);
}

void CRNG::GenMT()
{
	for(int i = 0; i < MT_SIZE; i++){ 
		
		int y = ((MT[i] & 0x80000000) + (MT[(i+1) % 624] & 0x7FFFFFFF));
		
		MT[i] = MT[(i + 397) % MT_SIZE] ^ (y >> 1);
		
		if((y % 2) != 0) // y is odd
			MT[i] = MT[i] ^ (0x9908B0DF);
	}
}

void CRNG::Seed(UINT n)
{
	Index = 0;
	MT[0] = (int)n;
	
	for(int i = 1; i < MT_SIZE; i++)
		MT[i] = (0x6C078965 * (MT[i-1] ^ (MT[i-1] >> 30)) + i);
}

UINT CRNG::Rand(UINT Range)
{
	if(Index == 0)
		GenMT();
	
	int y = MT[Index];
	y = y ^  (y >> 11);
	y = y ^ ((y << 7)  & (0x9D2C5680));
	y = y ^ ((y << 15) & (0xEFC60000));
	y = y ^  (y >> 18);
	
	Index++;
	if(Index >= MT_SIZE)
		Index = 0;
	
	if(Range == 0){
		return (UINT)y;
	} else {
		return (UINT)y % (Range+1); // <-- need testing!
	}
}

