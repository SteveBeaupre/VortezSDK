#pragma once

#include <Windows.h>
#include <Math.h>

#include "Preproc.h"

class _EXP_FUNC CVector
{
public:
	CVector();
	CVector(float x, float y);
	CVector(float x, float y, float z);
	CVector(float x, float y, float z, float w);

	float x,y,z,w;

	void Clear();

	void Set(float x, float y);
	void Set(float x, float y, float z);
	void Set(float x, float y, float z, float w);
	void Set(CVector v);

	void  Reverse();
	void  Normalize();
	float Magnitude();

	bool operator==(const CVector &v);
	bool operator!=(const CVector &v);

	CVector operator=(const CVector &v);

	CVector operator+=(const CVector &v);
	CVector operator-=(const CVector &v);
	CVector operator*=(const CVector &v);
	CVector operator/=(const CVector &v);

	CVector operator*=(float s);
	CVector operator/=(float s);
};

CVector _EXP_FUNC operator-(CVector v);

CVector _EXP_FUNC operator+(CVector v1, const CVector &v2);
CVector _EXP_FUNC operator-(CVector v1, const CVector &v2);
CVector _EXP_FUNC operator*(CVector v1, const CVector &v2);
CVector _EXP_FUNC operator/(CVector v1, const CVector &v2);

CVector _EXP_FUNC operator*(CVector v, float s);
CVector _EXP_FUNC operator/(CVector v, float s);
CVector _EXP_FUNC operator*(float s, CVector v);
CVector _EXP_FUNC operator/(float s, CVector v);

float   _EXP_FUNC DotProduct(const CVector &v1, const CVector &v2);
CVector _EXP_FUNC CrossProduct(const CVector &v1, const CVector &v2);

float   _EXP_FUNC Magnitude(const CVector &v);
CVector _EXP_FUNC Reverse(const CVector &v);
CVector _EXP_FUNC Normalize(const CVector &v);
