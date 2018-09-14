#pragma once
#include "vector3.h"

class Matrix3
{
public:
	union
	{

		struct
		{
			Vector3 xAxis;
			Vector3 yAxis;
			Vector3 zAxis;
		};
		Vector3 axis[3];
		float data[3][3];
	};
	
	Matrix3();
	Matrix3(float xx, float xy, float xz, float yx, float yy, float yz,
		float zx, float zy, float zz);

	Vector3& operator[](int index);
	Vector3 operator[](int index) const;

	operator float*();
	operator const float*() const;

	Matrix3 operator*(const Matrix3 &other) const;

	Vector3 operator*(const Vector3 &other) const;

	void setRotateX(float radian);
	void setRotateY(float radian);
	void setRotateZ(float radian);
};

