#include "Vec2.h"

Vec2::Vec2(int in_x, int in_y)
{
	x = in_x;
	y = in_y;
}

Vec2 Vec2::operator+(const Vec2 & rhs) const
{
	return Vec2(x + rhs.x, y + rhs.y);
}

Vec2 Vec2::operator-(const Vec2 & rhs) const
{
	return Vec2(x - rhs.x, y - rhs.y);
}

Vec2 Vec2::operator*(const int rhs) const
{
	return Vec2(x * rhs, y * rhs);
}

Vec2 Vec2::operator/(const int rhs) const
{
	return Vec2(x / rhs, y / rhs);
}

Vec2 & Vec2::operator+=(const Vec2 & rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Vec2 & Vec2::operator-=(const Vec2 & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}
