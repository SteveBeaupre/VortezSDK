#include "SieveOfAtkin.h"

CSieveOfAtkin::CSieveOfAtkin()
{
	limit  = 0;
	sieve  = NULL;
}

CSieveOfAtkin::CSieveOfAtkin(int range)
{
	limit  = 0;
	sieve  = NULL;
	GenSieve(range);
}

CSieveOfAtkin::~CSieveOfAtkin()
{
	DelSieve();
}

void CSieveOfAtkin::GenSieve(int range)
{
	DelSieve();

	if(range < 4)
		range = 4;

	//Create the various different variables required
	limit = range+1;
	int root = (int)ceil(sqrtf((float)limit));

	sieve = new bool[limit];
	ZeroMemory(sieve, limit);

	for (int x = 1; x <= root; x++)
	{
		for (int y = 1; y <= root; y++)
		{
			//Main part of Sieve of Atkin
			int n = (4*x*x)+(y*y);
			if (n <= limit && (n % 12 == 1 || n % 12 == 5)) sieve[n] ^= true;
			n = (3*x*x)+(y*y);
			if (n <= limit && n % 12 == 7) sieve[n] ^= true;
			n = (3*x*x)-(y*y);
			if (x > y && n <= limit && n % 12 == 11) sieve[n] ^= true;
		}
	}
	//Mark all multiples of squares as non-prime
	for (int r = 5; r <= root; r++) if (sieve[r]) 
		for (int i = r*r; i < limit; i += r*r)
			sieve[i] = false;

	sieve[2] = true;
	sieve[3] = true;
}

void CSieveOfAtkin::DelSieve()
{
	SAFE_DELETE_ARRAY(sieve);
	limit = 0;
}

bool CSieveOfAtkin::IsPrime(int n)
{
	if(sieve && n <= limit)
		return sieve[n];

	return false;
}
