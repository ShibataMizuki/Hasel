#include"CollisionHelper.h"

#include"../Hasel/Math/MathInc.h"
#include"../Hasel/Shape/ShapeInc.h"

using namespace hasel;
using namespace hasel::math;
using namespace hasel::shape;
using namespace hasel::cs2d;

bool CollisionHelper::isIntersect(Shape* shapeA, Shape* shapeB, const Vector2& posA, const Vector2& posB)
{
	if (!shapeA->getAABB().isIntersect(shapeB->getAABB()))
		return false;

	bool result = false;

	auto circleA = dynamic_cast<Circle*>(shapeA);
	auto circleB = dynamic_cast<Circle*>(shapeB);

	if (circleA&&circleB)
		result = isIntersectCircle(circleA, circleB, posA, posB);

	return result;
}

bool CollisionHelper::isIntersectCircle(Circle* circleA, Circle* circleB, const Vector2& posA, const Vector2& posB)
{
	float x = posA.x - posB.x;
	float y = posA.y - posB.y;
	float r = circleA->getRadius() + circleB->getRadius();
	return x*x + y*y <= r*r;
}