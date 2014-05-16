#include "Matrix.h"

CMatrix::CMatrix()
{
	SetIdentity();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CMatrix::Clear()
{
	ZeroMemory(&Matrix[0][0], sizeof(Matrix));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

float* CMatrix::GetMatrix()
{
	return &Matrix[0][0];
}

void CMatrix::SetIdentity()
{
	Clear();

	for(int i = 0; i < 4; i++)
		Matrix[i][i] = 1.0f;
}

void CMatrix::Scale(float x, float y, float z)
{
	Matrix[0][0] *= x;
	Matrix[1][1] *= y;
	Matrix[2][2] *= z;
}

void CMatrix::Scale(CVector &v)
{
	Scale(v.x, v.y, v.z);
}

void CMatrix::Translate(float x, float y, float z)
{
	Matrix[3][0] += x;
	Matrix[3][1] += y;
	Matrix[3][2] += z;
}

void CMatrix::Translate(CVector &v)
{
	Translate(v.x, v.y, v.z);
}

void CMatrix::RotateOnXAxis(float x)
{
	float Angle = AngleToRadian(x);

	CMatrix tmp;
	tmp.Matrix[1][2] = sinf(Angle);
	tmp.Matrix[2][2] = tmp.Matrix[1][1] = cosf(Angle);
	tmp.Matrix[2][1] = -tmp.Matrix[1][2];

	*this *= tmp;
}

void CMatrix::RotateOnYAxis(float y)
{
	float Angle = AngleToRadian(y);
	
	CMatrix tmp;
	tmp.Matrix[2][0] = sinf(Angle);
	tmp.Matrix[2][2] = tmp.Matrix[0][0] = cosf(Angle);
	tmp.Matrix[0][2] = -tmp.Matrix[2][0];

	*this *= tmp;
}

void CMatrix::RotateOnZAxis(float z)
{
	float Angle = AngleToRadian(z);

	CMatrix tmp;
	tmp.Matrix[0][1] = sinf(Angle);
	tmp.Matrix[1][1] = tmp.Matrix[0][0] = cosf(Angle);
	tmp.Matrix[1][0] = -tmp.Matrix[0][1];

	*this *= tmp;
}

void CMatrix::Rotate(float x, float y, float z)
{
	CMatrix xMatrix, yMatrix, zMatrix;

	xMatrix.RotateOnXAxis(x);
	yMatrix.RotateOnXAxis(y);
	zMatrix.RotateOnXAxis(z);
	
	*this *= (zMatrix * yMatrix * xMatrix);
}

void CMatrix::Rotate(CVector &v)
{
	Rotate(v.x, v.y, v.z);
}

void CMatrix::Add(const CMatrix &m)
{
	for(int y = 0; y < 4; y++){
		for(int x = 0; x < 4; x++){
			Matrix[y][x] += m.Matrix[y][x];	
		}
	}
}

void CMatrix::Subtract(const CMatrix &m)
{
	for(int y = 0; y < 4; y++){
		for(int x = 0; x < 4; x++){
			Matrix[y][x] -= m.Matrix[y][x];	
		}
	}
}

void CMatrix::Multiply(const CMatrix &m)
{
	CMatrix Res;
	for(int y = 0; y < 4; y++){
		for(int x = 0; x < 4; x++){
			Res.Matrix[y][x] = (Matrix[y][0] * m.Matrix[0][x]) + 
							   (Matrix[y][1] * m.Matrix[1][x]) + 
							   (Matrix[y][2] * m.Matrix[2][x]) + 
							   (Matrix[y][3] * m.Matrix[3][x]);	
		}
	}

	*this = Res;
}

void CMatrix::ScalarMultiply(float s)
{
	for(int y = 0; y < 4; y++){
		for(int x = 0; x < 4; x++){
			Matrix[y][x] *= s;	
		}
	}
}

void CMatrix::ScalarDivide(float s)
{
	ScalarMultiply(1/s);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CMatrix::operator==(const CMatrix &m)
{
	return memcmp(&Matrix[0][0], &m.Matrix[0][0], sizeof(Matrix)) == 0;
}

bool CMatrix::operator!=(const CMatrix &m)
{
	return !(operator==(m));
}

CMatrix CMatrix::operator=(const CMatrix &m)
{
	memcpy(&Matrix[0][0], &m.Matrix[0][0], sizeof(Matrix));
	return *this;
}

CMatrix CMatrix::operator+=(const CMatrix &m)
{
	Add(m);
	return *this;
}

CMatrix CMatrix::operator-=(const CMatrix &m)
{
	Subtract(m);
	return *this;
}

CMatrix CMatrix::operator*=(const CMatrix &m)
{
	Multiply(m);
	return *this;
}

CMatrix CMatrix::operator*=(float s)
{
	ScalarMultiply(s);
	return *this;
}

CMatrix CMatrix::operator/=(float s)
{
	ScalarDivide(s);
	return *this;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

CMatrix operator+(CMatrix m1, const CMatrix &m2)
{
	m1.Add(m2);
	return m1;
}

CMatrix operator-(CMatrix m1, const CMatrix &m2)
{
	m1.Subtract(m2);
	return m1;
}

CMatrix operator*(CMatrix m1, const CMatrix &m2)
{
	m1.Multiply(m2);
	return m1;
}

CMatrix operator*(CMatrix m1, float s)
{
	m1.ScalarMultiply(s);
	return m1;
}

CMatrix operator*(float s, CMatrix m1)
{
	m1.ScalarMultiply(s);
	return m1;
}

CMatrix operator/(CMatrix m1, float s)
{
	m1.ScalarDivide(s);
	return m1;
}

CMatrix operator/(float s, CMatrix m1)
{
	m1.ScalarDivide(s);
	return m1;
}

CVector operator*(const CMatrix &m1, CVector v1)
{
	ApplyMatrixToVector(v1, m1);
	return v1;
}

CVector operator*(CVector v1, const CMatrix &m1)
{
	ApplyMatrixToVector(v1, m1);
	return v1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ApplyMatrixToVector(CVector &v, const CMatrix &m)
{
	CVector Tmp(v.x, v.y, v.z, v.w);
	v.x = (m.Matrix[0][0] * Tmp.x) + (m.Matrix[1][0] * Tmp.y) + (m.Matrix[2][0] * Tmp.z) + (m.Matrix[3][0] * Tmp.w);
	v.y = (m.Matrix[0][1] * Tmp.x) + (m.Matrix[1][1] * Tmp.y) + (m.Matrix[2][1] * Tmp.z) + (m.Matrix[3][1] * Tmp.w);
	v.z = (m.Matrix[0][2] * Tmp.x) + (m.Matrix[1][2] * Tmp.y) + (m.Matrix[2][2] * Tmp.z) + (m.Matrix[3][2] * Tmp.w);
	v.w = (m.Matrix[0][3] * Tmp.x) + (m.Matrix[1][3] * Tmp.y) + (m.Matrix[2][3] * Tmp.z) + (m.Matrix[3][3] * Tmp.w);
}

float AngleToRadian(float Angle)
{
	static const float PI = 3.141592653589793f;
	static const float rad = (PI * 2.0f) / 360.0f;

	return Angle * rad;
}

