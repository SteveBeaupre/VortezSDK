#include "RawBuffer.h"

CRawBuffer::CRawBuffer()
{
	BufSize = 0; 
	pBuf = NULL;
}

CRawBuffer::CRawBuffer(UINT Size)
{
	BufSize = 0; 
	pBuf = NULL; 
	Allocate(Size);
}

CRawBuffer::~CRawBuffer()
{
	Free();
}

bool CRawBuffer::IsAllocated()
{
	return pBuf != NULL;
}

bool CRawBuffer::Allocate(UINT Size, BOOL EraseBuf)
{
	if(IsAllocated()){
		if(BufSize != Size){
			Free();
		} else {
			if(EraseBuf)
				Erase();
			return true;
		}
	}

	if(!IsAllocated()){
		pBuf = new BYTE[Size]; 
		if(IsAllocated()){
			BufSize = Size; 
			Erase(); 
			return true;
		}
	}

	return false;
}

void CRawBuffer::Erase()
{
	if(IsAllocated())
		ZeroMemory(pBuf, BufSize);
}

void CRawBuffer::Set(BYTE Val)
{
	if(IsAllocated())
		memset(pBuf, Val, BufSize);
}

void CRawBuffer::Free()
{
	if(IsAllocated()){
		SAFE_DELETE_ARRAY(pBuf); 
		BufSize = 0;
	}
}

UINT CRawBuffer::GetSize()
{
	return BufSize;
}

void CRawBuffer::Resize(UINT NewSize)
{
	if(NewSize == 0){
		Free();
	} else if(NewSize == BufSize){ 
		return;
	} else if(NewSize < BufSize){ 
		BufSize = NewSize;
	} else if(NewSize > BufSize){ 
		Allocate(BufSize);
	}
}

BYTE* CRawBuffer::GetBuffer(UINT Offset)
{
	return &pBuf[Offset];
}

DWORD CRawBuffer::Hash()
{
	if(BufSize > 0){
		CCRC32 crc;
		return crc.Generate(pBuf, BufSize);
	}

	return 0;
}

void CRawBuffer::Encrypt(UINT Key)
{
	if(BufSize > 0){
		CEncryptor Encryptor;
		Encryptor.Initialize(&Key, sizeof(UINT));
		Encryptor.Encrypt(pBuf, BufSize);
	}
}

void CRawBuffer::Decrypt(UINT Key)
{
	Encrypt(Key);
}

bool CRawBuffer::LoadFromFile(char *fname)
{
	CFileManager FileManager;
	if(!FileManager.DoesExist(fname))
		return false;

	UINT fSize = FileManager.GetSize(fname);
	if(fSize == 0)
		return false;

	CFileIO f;
	if(f.OpenForReading(fname)){
		
		Allocate(fSize);
		f.Read(pBuf, fSize);	

		f.Close();

		return true;
	}

	return false;
}

bool CRawBuffer::SaveToFile(char *fname, UINT MaxSize)
{
	UINT fSize = GetSize();

	if(MaxSize > 0 && fSize > MaxSize)
		fSize = MaxSize;

	CFileIO f;
	if(f.OpenForWriting(fname)){
		
		if(fSize > 0)
			f.Write(pBuf, fSize);	

		f.Close();

		return true;
	}

	return false;
}

