#pragma once

#include "Windows.h"
#include "stdio.h"

#include "crc32.h"
#include "RNG.h"
#include "RawBuffer.h"

#include "Preproc.h"

class _EXP_FUNC CEncryptor {
public:
	CEncryptor();
	~CEncryptor();
private:
	int  NumKeyChars;
	bool UseStrongEncryption;

	CRNG KeyRNG;
	CRNG *pKeyCharRNG;

	void GenKey(BYTE *pKey, DWORD KeySize, CRNG *rng);
	void XOR(BYTE *pBlock, BYTE *pKey, DWORD BlockSize);
public:
	void Initialize(void *pKey, UINT KeyLen, bool StrongEncryption = false);

	void Encrypt(void *pBuffer, DWORD BufferSize);
	void Decrypt(void *pBuffer, DWORD BufferSize);
};
