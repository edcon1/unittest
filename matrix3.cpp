#include "Matrix3.h"
#include "vector3.h"
#include <cmath>

Matrix3::Matrix3()
{
	xAxis = Vector3(1, 0, 0);
	yAxis = Vector3(0, 1, 0);
	zAxis = Vector3(0, 0, 1);
}

Matrix3::Matrix3(float xx, float xy, float xz, float yx, float yy,
	float yz, float zx, float zy, float zz)
{
	xAxis = Vector3(xx, xy, xz);
	yAxis = Vector3(yx, yy, yz);
	zAxis = Vector3(zx, zy, zz);
}

Vector3 & Matrix3::operator[](int index)
{
	return axis[index];
}

Vector3 Matrix3::operator[](int index) const
{
	return axis[index];
}

Matrix3::operator float*()
{
	return &data[0][0];
}

Matrix3::operator const float*() const
{
	return &data[0][0];
}

Matrix3 Matrix3::operator*(const Matrix3& other) const
{
	Matrix3 returnMatrix;

	// this is the example for (M11)
	returnMatrix.xAxis.x = xAxis.x * other.xAxis.x + yAxis.x * other.xAxis.y
		+ zAxis.x * other.xAxis.z;

	// this is the example for (M12)
	returnMatrix.yAxis.x = xAxis.x * other.yAxis.x + yAxis.x * other.yAxis.y
		+ zAxis.x * other.yAxis.z;

	// this is the example for (M13)
	returnMatrix.zAxis.x = xAxis.x * other.zAxis.x + yAxis.x * other.zAxis.y
		+ zAxis.x * other.zAxis.z;

	// this is the example for (M21)
	returnMatrix.xAxis.y = xAxis.y * other.xAxis.x + yAxis.y * other.xAxis.y
		+ zAxis.y * other.xAxis.z;

	// (this is the example for (M22)
	returnMatrix.yAxis.y = xAxis.y * other.yAxis.x + yAxis.y * other.yAxis.y
		+ zAxis.y * other.yAxis.z;

	//this is the example for (M23)
	returnMatrix.zAxis.y = xAxis.y * other.zAxis.x + yAxis.y * other.zAxis.y
		+ zAxis.y * other.zAxis.z;

	// (M31)
	returnMatrix.xAxis.z = xAxis.z * other.xAxis.x + yAxis.z * other.xAxis.y
		+ zAxis.z * other.xAxis.z;

	// (M32)
	returnMatrix.yAxis.z = xAxis.z * other.yAxis.x + yAxis.z * other.yAxis.y
		+ zAxis.z * other.yAxis.z;

	// (M33)
	returnMatrix.zAxis.z = xAxis.z * other.zAxis.x + yAxis.z * other.zAxis.y
		+ zAxis.z * other.zAxis.z;

	return returnMatrix;
}

Vector3 Matrix3::operator*(const Vector3 & other) const
{
	Vector3 returnVec;

	    returnVec.x = xAxis.x * other.x + yAxis.x * other.y + zAxis.x * other.z;

		returnVec.y = xAxis.y * other.x + yAxis.y * other.y + zAxis.y * other.z;

		returnVec.z = xAxis.z * other.x + yAxis.z * other.y + zAxis.z * other.z;

		return returnVec;
}

void Matrix3::setRotateX(float radian)
{
	xAxis = { 1, 0, 0 };
	yAxis = { 0, cosf(radian), sinf(radian) };
	zAxis = { 0, -sinf(radian), cosf(radian) };
}

void Matrix3::setRotateY(float radian)
{
	xAxis = { cosf(radian), 0, -sinf(radian) };
	yAxis = { 0, 1, 0 };
	zAxis = { sinf(radian), 0, cosf(radian) };
}

void Matrix3::setRotateZ(float radian)
{
	xAxis = { cosf(radian), sinf(radian), 0 };
	yAxis = { -sinf(radian), cosf(radian), 0 };
	zAxis = { 0, 0, 1 };
}


