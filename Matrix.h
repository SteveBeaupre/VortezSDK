#pragma once

#include "Vector.h"

class _EXP_FUNC CMatrix
{
public:
	CMatrix();

	float Matrix[4][4];

	float* GetMatrix();

	inline void Clear();
	inline void SetIdentity();

	inline void Scale(CVector &v);
	inline void Scale(float x, float y, float z);
	inline void Translate(CVector &v);
	inline void Translate(float x, float y, float z);
	inline void RotateOnXAxis(float x);
	inline void RotateOnYAxis(float y);
	inline void RotateOnZAxis(float z);
	inline void Rotate(CVector &v);
	inline void Rotate(float x, float y, float z);

	inline void Add(const CMatrix &m);
	inline void Subtract(const CMatrix &m);
	inline void Multiply(const CMatrix &m);
	inline void ScalarMultiply(float s);
	inline void ScalarDivide(float s);

	inline bool operator==(const CMatrix &m);
	inline bool operator!=(const CMatrix &m);

	CMatrix operator=(const CMatrix &m);

	CMatrix operator+=(const CMatrix &m);
	CMatrix operator-=(const CMatrix &m);
	CMatrix operator*=(const CMatrix &m);
	
	CMatrix operator*=(float s);
	CMatrix operator/=(float s);
};

CMatrix _EXP_FUNC operator+(CMatrix m1, const CMatrix &m2);
CMatrix _EXP_FUNC operator-(CMatrix m1, const CMatrix &m2);
CMatrix _EXP_FUNC operator*(CMatrix m1, const CMatrix &m2);

CMatrix _EXP_FUNC operator*(CMatrix m1, float s);
CMatrix _EXP_FUNC operator*(float s, CMatrix m1);
CMatrix _EXP_FUNC operator/(CMatrix m1, float s);
CMatrix _EXP_FUNC operator/(float s, CMatrix m1);

CVector _EXP_FUNC operator*(const CMatrix &m1, CVector v1);
CVector _EXP_FUNC operator*(CVector v1, const CMatrix &m1);

void  _EXP_FUNC ApplyMatrixToVector(CVector &v, const CMatrix &m);
float _EXP_FUNC AngleToRadian(float Angle);

