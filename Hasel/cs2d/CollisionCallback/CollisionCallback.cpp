#include "CollisionCallback.h"

#include"../Hasel/Hasel.h"

using namespace std;
using namespace hasel;
using namespace hasel::cs2d;

hasel::cs2d::CollisionCallbackBuilder::CollisionCallbackBuilder(int attributeA, int attributeB):
	m_attributeA(attributeA),m_attributeB(attributeB)
{
}

CollisionCallbackBuilder & hasel::cs2d::CollisionCallbackBuilder::addCallbacks(std::function<void(const uptr<RigidBody>&, const uptr<RigidBody>&)> callback)
{
	m_callbacks.push_back(callback);
	return *this;
}

sptr<CollisionCallback> hasel::cs2d::CollisionCallbackBuilder::buildShared()
{
	return move(make_shared<CollisionCallback>(*this));
}

uptr<CollisionCallback> hasel::cs2d::CollisionCallbackBuilder::buildUnique()
{
	return move(make_unique<CollisionCallback>(*this));
}

CollisionCallback * hasel::cs2d::CollisionCallbackBuilder::buildRaw()
{
	return new CollisionCallback(*this);
}

hasel::cs2d::CollisionCallback::CollisionCallback(const CollisionCallbackBuilder & builder):
	m_attributeA(builder.m_attributeA),
	m_attributeB(builder.m_attributeB),
	m_callbacks(builder.m_callbacks)
{
}

int hasel::cs2d::CollisionCallback::getAttributeA() const
{
	return m_attributeA;
}

int hasel::cs2d::CollisionCallback::getAttributeB() const
{
	return m_attributeB;
}

const std::vector<std::function<void(const uptr<RigidBody>&bodyA, const uptr<RigidBody>&bodyB)>>& hasel::cs2d::CollisionCallback::getCallbacks() const
{
	return m_callbacks;
}
