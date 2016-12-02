#include"AABB.h"
#include<iostream>
#include<algorithm>
using namespace std;
using namespace hasel::shape;
using namespace hasel::math;

const Vector2 & AABB::getCenterPosition() const
{
	return m_centerPos;
}

void AABB::setCenterPosition(const Vector2 & centerPos)
{
	m_centerPos = centerPos;
}

float AABB::getWidth() const
{
	return m_width;
}

float AABB::getHeight() const
{
	return m_height;
}

void AABB::setWidth(float width)
{
	m_width = width;
}

void AABB::setHeight(float height)
{
	m_height = height;
}

void hasel::shape::AABB::setSize(float width, float height)
{
	m_width = width;
	m_height = height;
}

Vector2 AABB::getUpper() const
{
	Vector2 upper;
	upper.x = m_centerPos.x + m_width / 2.f;
	upper.y = m_centerPos.y + m_height / 2.f;
	return move(upper);
}

Vector2 AABB::getLower() const
{
	Vector2 lower;
	lower.x = m_centerPos.x - m_width / 2.f;
	lower.y = m_centerPos.y - m_width / 2.f;
	return move(lower);
}


AABB::AABB(const Vector2 & centerPos, float width, float height) :
	m_centerPos(centerPos),m_width(width), m_height(height)
{
}

AABB::AABB(const Vector2 & lower, const Vector2 & upper)
{
	m_centerPos.x = (upper.x - lower.x) / 2.f;
	m_centerPos.y = (upper.y - lower.y) / 2.f;
	m_width = upper.x - lower.x;
	m_height = upper.y - lower.y;
}

bool AABB::isIntersect(const AABB & aabb) const
{
	Vector2 thisUpper = getUpper();
	Vector2 thisLower = getLower();
	Vector2 targetUpper = aabb.getUpper();
	Vector2 targetLower = aabb.getLower();

	return thisUpper.x > targetLower.x&&
		thisLower.x < targetUpper.x&&
		thisUpper.y>targetLower.y&&
		thisLower.y < targetUpper.y;
}


AABB AABB::merge(const AABB& aabb1, const AABB& aabb2)
{
	Vector2 retLower, retUpper;
	retLower.x = min(aabb1.getLower().x, aabb2.getLower().x);
	retLower.y = min(aabb1.getLower().y, aabb2.getLower().y);
	retUpper.x = max(aabb1.getUpper().x, aabb2.getUpper().x);
	retUpper.y = max(aabb1.getUpper().y, aabb2.getUpper().y);
	return AABB(retLower, retUpper);
}

void AABB::dump() const
{
	cout << "[Center]" << m_centerPos.dump() << endl;
	cout << "[Upper]" << getUpper().dump() << endl;
	cout << "[Lower]" << getLower().dump() << endl;
}