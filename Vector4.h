#pragma once

class Vector4

{
public:


	union
	{
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
		struct
		{
			float r;
			float b;
			float g;
			float y;
		};
		float data[4];

	};
	Vector4();
	Vector4(float x, float y, float z, float w);

	
	operator float*();
	operator const float*() const;

	float& operator[](int index);
	float operator[](int index) const;

	Vector4 operator+(const Vector4& other) const;
	Vector4 add(const Vector4 &other) const;

	Vector4 operator-(const Vector4 &other)const;
	Vector4 minus(const Vector4 &other) const;

	Vector4 operator*(const float &other) const;
	Vector4 times(const float &other) const;

	float dot(const Vector4& other) const;

	Vector4 cross(const Vector4& other) const;

	float magnitude()const;

	void normalise();

private:
};

Vector4 operator*(float other, const Vector4& vec);