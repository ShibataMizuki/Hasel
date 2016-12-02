#include "Circle.h"

using namespace std;
using namespace hasel::shape;
using namespace hasel;
using namespace hasel::math;

hasel::shape::Circle::Circle(const CircleBuilder & builder):
	Shape(builder.m_offset),m_radius(builder.m_radius)
{
	m_aabb = AABB(m_offset, m_radius*2.f, m_radius*2.f);
}

void Circle::setRadius(float radius)
{
	m_radius = radius;
}

float Circle::getRadius() const
{
	return m_radius;
}

hasel::shape::CircleBuilder::CircleBuilder(float radius):
	m_radius(radius),m_offset()
{
}

CircleBuilder * hasel::shape::CircleBuilder::setOffset(const Vector2 & offset)
{
	m_offset = offset;
	return this;
}

sptr<Circle> hasel::shape::CircleBuilder::buildShared()
{
	return move(make_shared<Circle>(*this));
}

uptr<Circle> hasel::shape::CircleBuilder::buildUnique()
{
	return move(make_unique<Circle>(*this));
}

Circle* hasel::shape::CircleBuilder::buildRaw()
{
	return new Circle(*this);
}