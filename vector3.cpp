#include "vector3.h"
#include <cmath>

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::operator float*()
{
	return data;
}

Vector3::operator const float*() const
{
	return data;
}

float & Vector3::operator[](int index)
{
	return data[index];
}

float Vector3::operator[](int index) const
{
	return data[index];
}

Vector3 Vector3::operator+(const Vector3 & other) const
{
	return add(other);
}

Vector3 Vector3::add(const Vector3 & other) const
{
	Vector3 returnVec;
	returnVec.x = x + other.x;
	returnVec.y = y + other.y;
	returnVec.z = z + other.z;
	return returnVec;
}

Vector3 Vector3::operator-(const Vector3 & other) const
{
	return minus(other);
}

Vector3 Vector3::minus(const Vector3 & other) const
{
	Vector3 returnVec;
	returnVec.x = x - other.x;
	returnVec.y = y - other.y;
	returnVec.z = z - other.z;
	return returnVec;
}

Vector3 Vector3::operator*(const float & other) const
{
	return times(other);
}

Vector3 Vector3::times(const float & other) const
{
	Vector3 returnVec;
	returnVec.x = x * other;
	returnVec.y = y * other;
	returnVec.z = z * other;
	return returnVec;
}

Vector3 operator*(float other, const Vector3& vec)
{
	Vector3 returnVec;
	returnVec.x = vec.x * other;
	returnVec.y = vec.y * other;
	returnVec.z = vec.z * other;
	return returnVec;
}

float Vector3::dot(const Vector3& other) const
{
	return x * other.x + y * other.y + z* other.z;
}

Vector3 Vector3::cross(const Vector3 & other) const
{
	return Vector3(y * other.z - z* other.y,
		z * other.x - x * other.z, 
		x * other.y - y * other.x );
}

float Vector3::magnitude() const
{
	return sqrt(x * x + y * y + z * z);
}

void Vector3::normalise()
{
	float L = magnitude();
	x = x / L;
	y = y / L;
	z = z / L;
}



