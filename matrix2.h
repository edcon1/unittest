#pragma once
#include "Vector2.h"
#include <cmath>

class Matrix2
{
public:
	union
	{
		struct 
		{
			Vector2 xAxis;
			Vector2 yAxis;
		};
		Vector2 axis[2];
		float data[2][2];
	};
	Matrix2();
	Matrix2(float xx, float xy, float yx, float yy);

	Vector2& operator[](int index);
	Vector2 operator[](int index) const;



	operator float*();
	operator const float*() const;

	Matrix2 operator*(const Matrix2& other) const;

	Vector2 operator*(const Vector2& other) const;

	void setRotate(float radian);
	

private:

};