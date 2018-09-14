#include "martix4.h"	
#include "vector4.h"

Matrix4::Matrix4()
{
	xAxis = Vector4(1, 0, 0, 0);
	yAxis = Vector4(0, 1, 0, 0);
	zAxis = Vector4(0, 0, 1, 0);
	wAxis = Vector4(0, 0, 0, 1);
}

Matrix4::Matrix4(float xx, float xy, float xz, float xw, float yx, float yy,
	float yz, float yw, float zx, float zy, float zz, float zw,
	float wx, float wy, float wz, float ww)
{
	xAxis = Vector4(xx, xy, xz, xw);
	yAxis = Vector4(yx, yy, yz, yw);
	zAxis = Vector4(zx, zy, zz, zw);
	wAxis = Vector4(wx, wy, wz, ww);
}

Vector4 & Matrix4::operator[](int index)
{
	return axis[index];
}

Vector4 Matrix4::operator[](int index) const
{
	return axis[index];
}

Matrix4::operator float*()
{
	return &data[0][0];
}

Matrix4::operator const float*() const
{
	return &data[0][0];
}

Vector4 Matrix4::operator*(const Vector4 & other) const
{
	return Vector4();
}

Matrix4 Matrix4::operator*(const Matrix4& other) const
{
	Matrix4 returnMatrix;

	// this is the example for (M11)
	returnMatrix.xAxis.x = xAxis.x * other.xAxis.x + yAxis.x * other.xAxis.y
		+ zAxis.x * other.xAxis.z + wAxis.x * other.xAxis.w;

	// this is the example for (M12)
	returnMatrix.yAxis.x = xAxis.x * other.yAxis.x + yAxis.x * other.yAxis.y
		+ zAxis.x * other.yAxis.z + wAxis.x * other.yAxis.w;

	// this is the example for (M13)
	returnMatrix.zAxis.x = xAxis.x * other.zAxis.x + yAxis.x * other.zAxis.y 
		+ zAxis.x * other.zAxis.z + wAxis.x * other.zAxis.w;

	// this is the example for (M14)
	returnMatrix.wAxis.x = xAxis.x * other.wAxis.x + yAxis.x * other.wAxis.y
		+ zAxis.x * other.wAxis.z + wAxis.x * other.wAxis.w;

	// this is the example for (M21)
	returnMatrix.xAxis.y = xAxis.y * other.xAxis.x + yAxis.y * other.xAxis.y
		+ zAxis.y * other.xAxis.z + wAxis.y * other.xAxis.w;

	// (this is the example for (M22)
	returnMatrix.yAxis.y = xAxis.y * other.yAxis.x + yAxis.y * other.yAxis.y
		+ zAxis.y * other.yAxis.z + wAxis.y * other.yAxis.w;

	//this is the example for (M23)
	returnMatrix.zAxis.y = xAxis.y * other.zAxis.x + yAxis.y * other.zAxis.y
		+ zAxis.y * other.zAxis.z + wAxis.y * other.zAxis.w;

	// this is the example for (M24)
	returnMatrix.wAxis.y = xAxis.y * other.wAxis.x + yAxis.y * other.wAxis.y
		+ yAxis.z * other.wAxis.z + yAxis.w * other.wAxis.w;

	// (M31)
	returnMatrix.xAxis.z = xAxis.z * other.xAxis.x + yAxis.z * other.xAxis.y
		+ zAxis.z * other.xAxis.z + wAxis.z * other.xAxis.w;

	// (M32)
	returnMatrix.yAxis.z = xAxis.z * other.yAxis.x + yAxis.z * other.yAxis.y
		+ zAxis.z * other.yAxis.z + wAxis.z * other.yAxis.w;

	// (M33)
	returnMatrix.zAxis.z = xAxis.z * other.zAxis.x + yAxis.z * other.zAxis.y
		+ zAxis.z * other.zAxis.z + wAxis.z* other.zAxis.w;

	//(M34)
	returnMatrix.wAxis.z = xAxis.z * other.wAxis.x + yAxis.z * other.wAxis.y
		+ zAxis.z * other.wAxis.z + wAxis.z * other.wAxis.w;

	//(M41)
	returnMatrix.xAxis.w = xAxis.w * other.xAxis.x + yAxis.w * other.xAxis.y
		+ zAxis.w * other.xAxis.z + wAxis.w * other.xAxis.w;

	//(M42)
	returnMatrix.yAxis.w = xAxis.w * other.yAxis.x + yAxis.w * other.yAxis.y
		+ zAxis.w * other.yAxis.z + wAxis.w * other.yAxis.w;

	//(M43)
	returnMatrix.zAxis.w = xAxis.w * other.zAxis.x + yAxis.w * other.zAxis.y
		+ zAxis.w * other.zAxis.z + wAxis.w * other.zAxis.w;

	//(M44)
	returnMatrix.wAxis.w = xAxis.w * other.wAxis.x + yAxis.w * other.wAxis.y
		+ zAxis.w * other.wAxis.z + wAxis.w * other.wAxis.w;


	return returnMatrix;

}
