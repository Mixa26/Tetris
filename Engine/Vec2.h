#pragma once

class Vec2
{
public:
	Vec2() = default;
	Vec2(int in_x, int in_y);
	Vec2 operator+(const Vec2& rhs) const;
	Vec2 operator-(const Vec2& rhs) const;
	Vec2 operator*(const int rhs) const;
	Vec2 operator/(const int rhs) const;
	Vec2& operator+=(const Vec2& rhs);
	Vec2& operator-=(const Vec2& rhs);
public:
	int x;
	int y;
};