#pragma once


class Vector3
{
public:
	union
	{
		struct
		{
			float x;
			float y;
			float z;
		};
		struct
		{
			float r;
			float g;
			float b;
		};
		float data[3];

	};
	Vector3();
	Vector3(float x, float y, float z);

	operator float*();
	operator const float*() const;

	float& operator[](int index);
	float operator[](int index) const;

	Vector3 operator+(const Vector3& other) const;
	Vector3 add(const Vector3 &other)const;

	Vector3 operator-(const Vector3 &other) const; 
	Vector3 minus(const Vector3 &other)const;

	Vector3 operator*(const float& other) const;
	Vector3 times(const float &other) const;

	float dot(const Vector3& other) const;

	Vector3 cross(const Vector3& other) const;

	float magnitude() const;

	void normalise();


private:
};

Vector3 operator*(float other, const Vector3& vec);
