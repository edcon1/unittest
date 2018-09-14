#include "vector4.h"
#include <cmath>

Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

Vector4::Vector4(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vector4::operator float*()
{
	return data;
}

Vector4::operator const float*() const
{
	return data;
}

Vector4 Vector4::operator+(const Vector4 & other) const
{
	return add(other);
}

Vector4 Vector4::add(const Vector4 & other) const
{
	Vector4 returnVec;
	returnVec.x = x + other.x;
	returnVec.y = y + other.y;
	returnVec.z = z + other.z;
	returnVec.w = w + other.w;
	return returnVec;
}

Vector4 Vector4::operator-(const Vector4 & other) const
{
	return minus(other);
}

Vector4 Vector4::minus(const Vector4 &other) const
{
	Vector4 returnVec;
	returnVec.x = x - other.x;
	returnVec.y = y - other.y;
	returnVec.z = z - other.z;
	returnVec.w = w - other.w;
	return returnVec;
}

Vector4 Vector4::operator*(const float &other) const
{
	return times(other);
}

Vector4 Vector4::times(const float &other) const
{
	Vector4 returnVec;
	returnVec.x = x * other;
	returnVec.y = y * other;
	returnVec.z = z * other;
	returnVec.w = w * other;
	return returnVec;
}



float Vector4::dot(const Vector4 & other) const
{
	return x * other.x + y * other.y + z * other.z + w * other.w;
}

Vector4 Vector4::cross(const Vector4 & other) const
{
	return Vector4(y * other.z - z * other.y,
		z * other.x - x * other.z,
		x * other.y - y * other.x, 0);
}

float Vector4::magnitude() const
{
	return sqrt(x * x + y * y + z * z);
}

void Vector4::normalise()
{
	float L = magnitude();
	x = x / L;
	y = y / L;
	z = z / L;

}

Vector4 operator*(float other, const Vector4& vec)
{
	Vector4 returnVec;
	returnVec.x = vec.x * other;
	returnVec.y = vec.y * other;
	returnVec.z = vec.z * other;
	returnVec.w = vec.w * other;
	return returnVec;
}

float& Vector4::operator[](int index)
{
	return data[index];
}

float Vector4::operator[](int index) const
{
	return data[index];
}
