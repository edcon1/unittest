#pragma once

class Vector2
{
public:
	union
	{
		struct
		{
			float x;
			float y;
		};

		struct
		{
			float r;
			float b;
		};
		float data[2];
	};
	Vector2();
	Vector2(float x, float y);

	operator float*();
	operator const float*() const;

	float& operator[](int index);
	float operator[](int index) const;

	Vector2 operator+(const Vector2& other) const;
	Vector2 add(const Vector2& other) const;

	Vector2 operator-(const Vector2& other) const;
	Vector2 minus(const Vector2& other) const;

	Vector2 operator*(const float& other) const;
	Vector2 times(const float& other) const;

	float dot(const Vector2& other) const;

	float magnitude() const;

	void normalise();

private:
};

Vector2 operator*(float other, const Vector2& vec);



