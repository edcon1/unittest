#include "vector2.h"
#include <cmath>

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::operator float*()
{
	return data;
}

Vector2::operator const float*() const
{
	return data;
}

float & Vector2::operator[](int index)
{
	return data[index];
}

float Vector2::operator[](int index) const
{
	return data[index];
}

Vector2 Vector2::operator+(const Vector2& other) const
{
	return add(other);
}

Vector2 Vector2::add(const Vector2& other) const
{
	Vector2 returnVec;
	returnVec.x = x + other.x;
	returnVec.y = y + other.y;
	return returnVec;
}

Vector2 Vector2::operator-(const Vector2& other) const
{
	return minus(other);
}

Vector2 Vector2::minus(const Vector2& other) const
{
	Vector2 returnVec;
	returnVec.x = x - other.x;
	returnVec.y = y - other.y;
	return returnVec;
}

Vector2 Vector2::operator*(const float& other) const
{
	return times(other);
}

Vector2 Vector2::times(const float& other)  const
{
	Vector2 returnVec;
	returnVec.x = x * other;
	returnVec.y = y * other;
	return returnVec;
}

float Vector2::dot(const Vector2 & other) const
{
	return x * other.x + y * other.y;
}

float Vector2::magnitude() const
{
	return sqrt(x* x + y * y);
}

void Vector2::normalise()
{
	float L = magnitude();
	x = x / L;
	y = y / L;
}

Vector2 operator*(float other, const Vector2& vec)
{
	Vector2 returnVec;

	returnVec.x;
	returnVec.x = vec.x * other;
	returnVec.y = vec.y * other;
	return returnVec;
}




