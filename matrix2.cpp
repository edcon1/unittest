#include "vector2.h"
#include "matrix2.h"


Matrix2::Matrix2()
{
	xAxis = Vector2(1, 0);
	yAxis = Vector2(0, 1);
}

Matrix2::Matrix2(float xx, float xy, float yx, float yy)
{
	xAxis = Vector2(xx, xy);
	yAxis = Vector2(yx, yy);
}

Vector2 & Matrix2::operator[](int index)
{
	return axis[index];
}

Vector2 Matrix2::operator[](int index) const
{
	return axis[index];
}

Matrix2::operator float*()
{
	return &data[0][0];
}

Matrix2::operator const float*() const
{
	return &data[0][0];
}

Matrix2 Matrix2::operator*(const Matrix2& other) const
{
	Matrix2 returnMatrix;


	// this is the example for (M11)
	returnMatrix.xAxis.x = xAxis.x * other.xAxis.x + yAxis.x * other.xAxis.y;
		

	// this is the example for (M12)
	returnMatrix.yAxis.x = xAxis.x * other.yAxis.x + yAxis.x * other.yAxis.y;
		
	// this is the example for (M21)
	returnMatrix.xAxis.y = xAxis.y * other.xAxis.x + yAxis.y * other.xAxis.y;


	// (this is the example for (M22)
	returnMatrix.yAxis.y = xAxis.y * other.yAxis.x + yAxis.y * other.yAxis.y;

	return returnMatrix;
	
}