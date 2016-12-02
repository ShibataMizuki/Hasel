#include "Shape.h"

using namespace hasel::shape;

void hasel::shape::Shape::setOffset(const hasel::math::Vector2 & offset)
{
	m_offset = offset;
}

const hasel::math::Vector2 & hasel::shape::Shape::getOffset() const
{
	return m_offset;
}

const AABB & hasel::shape::Shape::getAABB() const
{
	return m_aabb;
}
