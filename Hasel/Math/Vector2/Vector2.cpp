#include"Vector2.h"
#include<cmath>
#include<iostream>
#include<sstream>

using namespace std;

using namespace hasel::math;

hasel::math::Vector2::Vector2() :
	x(0.f), y(0.f)
{
}

hasel::math::Vector2::Vector2(float x, float y) :
	x(x), y(y)
{
}

Vector2 Vector2::operator+(const Vector2 & rv)const
{
	return std::move(Vector2(x + rv.x, y + rv.y));
}

Vector2 Vector2::operator-(const Vector2 & rv)const
{
	return std::move(Vector2(x - rv.x, y - rv.y));
}

Vector2 Vector2::operator*(float rv)const
{
	return std::move(Vector2(x*rv, y*rv));
}

Vector2 Vector2::operator/(float rv)const
{
	return std::move(Vector2(x / rv, y / rv));
}

void Vector2::operator+=(const Vector2 & rv)
{
	*this = *this + rv;
}

void Vector2::operator-=(const Vector2 & rv)
{
	*this = *this - rv;
}

float Vector2::getLength() const
{
	return sqrtf(x*x + y*y);
}

void Vector2::normalize()
{
	float length = getLength();
	x /= length;
	y /= length;
}

Vector2 Vector2::getNormalized() const
{
	float length = getLength();
	return std::move(Vector2(x / length, y / length));
}

float Vector2::dot(const Vector2 & rv) const
{
	return x*rv.x + y*rv.y;
}

float Vector2::cross(const Vector2 & rv) const
{
	return x*rv.y - y*rv.x;
}

std::string Vector2::dump() const
{
	ostringstream out;
	out << x << "," << y;
	return move(out.str());
}
