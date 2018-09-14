#pragma once
#include "vector4.h"
#include <cmath>

class Matrix4
{
public:
	union 
	{
		struct
		{
			Vector4 xAxis;
			Vector4 yAxis;
			Vector4 zAxis;
			Vector4 wAxis;
		};
		Vector4 axis[4];
		float data[4][4];
	};
	Matrix4();
	Matrix4(float xx, float xy, float xz, float xw, float yx, float yy,
		float yz, float yw, float zx, float zy, float zz, float zw,
		float wx, float wy, float wz, float ww);

	Vector4& operator[](int index);
	Vector4 operator[](int index) const;

	operator float*();
	operator const float*() const;

	Vector4 operator*(const Vector4 &other) const;
	
	Matrix4 operator*(const Matrix4& other) const;

	void setRotateX(float radian);
	void setRotateY(float radian);
	void setRotateZ(float radian);

};