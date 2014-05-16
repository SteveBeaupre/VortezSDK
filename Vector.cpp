#include "Vector.h"

CVector::CVector()
{
	Clear();
}

CVector::CVector(float x, float y)
{
	Set(x,y, 0.0f, 0.0f);
}

CVector::CVector(float x, float y, float z)
{
	Set(x,y,z, 0.0f);
}

CVector::CVector(float x, float y, float z, float w)
{
	Set(x,y,z,w);
}

void CVector::Set(float x, float y)
{
	Set(x,y, 0.0f, 0.0f);
}

void CVector::Set(float x, float y, float z)
{
	Set(x,y,z, 0.0f);
}

void CVector::Set(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

void CVector::Set(CVector v)
{
	Set(v.x, v.y, v.z, v.w);
}

void CVector::Clear()
{
	Set(0.0f, 0.0f, 0.0f, 0.0f);
}

float CVector::Magnitude()
{
	return sqrtf((x*x)+(y*y)+(z*z));
}

void CVector::Reverse()
{
	x = -x;
	y = -y;
	z = -z;
}

void CVector::Normalize()
{
	float m = Magnitude();
	if(m == 0.0f)
		return;

	x /= m;
	y /= m;
	z /= m;
}

CVector CVector::operator=(const CVector &v)
{
	Set(v);
	return *this;
}

bool CVector::operator==(const CVector &v)
{
	return (x == v.x && y == v.y && z == v.z && w == v.w);
}

bool CVector::operator!=(const CVector &v)
{
	return !(operator==(v));
}

CVector CVector::operator+=(const CVector &v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

CVector CVector::operator-=(const CVector &v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

CVector CVector::operator*=(const CVector &v)
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return *this;
}

CVector CVector::operator/=(const CVector &v)
{
	x /= v.x;
	y /= v.y;
	z /= v.z;
	return *this;
}

CVector CVector::operator*=(float s)
{
	x *= s;
	y *= s;
	z *= s;
	return *this;
}

CVector CVector::operator/=(float s)
{
	x /= s;
	y /= s;
	z /= s;
	return *this;
}

CVector operator-(CVector v)
{
	CVector Tmp(-v.x, -v.y, -v.z);
	return Tmp;
}

CVector operator+(CVector v1, const CVector &v2)
{
	v1.Set(v1.x+v2.x, v1.y+v2.y, v1.z+v2.z);
	return v1;
}

CVector operator-(CVector v1, const CVector &v2)
{
	v1.Set(v1.x-v2.x, v1.y-v2.y, v1.z-v2.z);
	return v1;
}

CVector operator*(CVector v1, const CVector &v2)
{
	v1.Set(v1.x*v2.x, v1.y*v2.y, v1.z*v2.z);
	return v1;
}

CVector operator/(CVector v1, const CVector &v2)
{
	v1.Set(v1.x/v2.x, v1.y/v2.y, v1.z/v2.z);
	return v1;
}

CVector operator*(CVector v, float s)
{
	v.Set(v.x*s, v.y*s, v.z*s);
	return v;
}

CVector operator/(CVector v, float s)
{
	v.Set(v.x/s, v.y/s, v.z/s);
	return v;
}

CVector operator*(float s, CVector v)
{
	v.Set(v.x*s, v.y*s, v.z*s);
	return v;
}

CVector operator/(float s, CVector v)
{
	v.Set(v.x/s, v.y/s, v.z/s);
	return v;
}

float DotProduct(const CVector &v1, const CVector &v2)
{
	return ((v1.x*v2.x) + (v1.y*v2.y) + (v1.z*v2.z));
}

CVector CrossProduct(const CVector &v1, const CVector &v2)
{
	CVector Tmp(((v1.y*v2.z)-(v1.z*v2.y)), ((v1.x*v2.z)+(v1.z*v2.x)), ((v1.x*v2.y)-(v1.y*v2.x)));
	return Tmp;
}

float Magnitude(const CVector &v)
{
	CVector Tmp(v);
	return Tmp.Magnitude();
}

CVector Reverse(const CVector &v)
{
	CVector Tmp(v);
	Tmp.Reverse();
	return Tmp;
}

CVector Normalize(const CVector &v)
{
	CVector Tmp(v);
	Tmp.Normalize();
	return Tmp;
}

