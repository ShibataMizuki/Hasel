#include"ShapeHelper.h"

#include"Hasel/Hasel.h"

using namespace std;
using namespace hasel;
using namespace hasel::shape;
using namespace hasel::math;

AABB ShapeHelper::mergeAABB(const AABB& lhs, const AABB& rhs)
{
	Vector2 lowerL = lhs.getLower(), upperL = lhs.getUpper();
	Vector2 lowerR = rhs.getLower(), upperR = rhs.getUpper();
	Vector2 lower, upper;

	lower.x = min(lowerL.x, lowerR.x);
	lower.y = min(lowerL.y, lowerR.y);
	upper.x = max(upperL.x, upperR.x);
	upper.y = max(upperL.y, upperR.y);

	return move(AABB(lower, upper));
}

AABB ShapeHelper::createAABBFromShapes(const vector<Shape>& shapes, const Vector2& pos)
{
	AABB result = AABB(pos, 0.f, 0.f);
	for (auto shape : shapes)
	{
		AABB merger = shape.getAABB();
		merger.setCenterPosition(shape.getOffset() + pos);
		result = ShapeHelper::mergeAABB(result, merger);
	}
	return move(result);
}

AABB ShapeHelper::createAABBFromShapes(const vector<sptr<Shape>>& shapes, const Vector2& pos)
{
	AABB result = AABB(pos, 0.f, 0.f);
	for (auto shape : shapes)
	{
		AABB merger = shape->getAABB();
		merger.setCenterPosition(shape->getOffset() + pos);
		result = ShapeHelper::mergeAABB(result, merger);
	}
	return move(result);
}

AABB ShapeHelper::createAABBFromShapes(const vector<uptr<Shape>>& shapes, const Vector2& pos)
{
	AABB result = AABB(pos, 0.f, 0.f);
	for (auto& shape : shapes)
	{
		AABB merger = shape->getAABB();
		merger.setCenterPosition(shape->getOffset() + pos);
		result = ShapeHelper::mergeAABB(result, merger);
	}
	return move(result);
}