#include "World.h"

#include"../Hasel/Hasel.h"

using namespace std;

using namespace hasel;
using namespace hasel::shape;
using namespace hasel::cs2d;
using namespace hasel::memory;

sptr<World> hasel::cs2d::WorldBuilder::buildShared()
{
	return move(make_shared<World>(*this));
}

uptr<World> hasel::cs2d::WorldBuilder::buildUnique()
{
	return move(make_unique<World>(*this));
}

World * hasel::cs2d::WorldBuilder::buildRaw()
{
	return new World(*this);
}

bool hasel::cs2d::World::isCollisionRigidBody(RigidBody * bodyA, RigidBody * bodyB)
{
	bool result = false;

	auto& shapesA = bodyA->getShapes();
	auto& shapesB = bodyB->getShapes();

	for (auto& shapeA : shapesA)
	{
		for (auto& shapeB : shapesB)
		{
			result = CollisionHelper::isIntersect(
				shapeA.get(), shapeB.get(),
				bodyA->getPosition(), bodyB->getPosition());
			if (result)
				break;
		}
	}

	return result;
}

hasel::cs2d::World::World(const WorldBuilder & builder)
{
}

uwptr<RigidBody> hasel::cs2d::World::addRigidBody(uptr<RigidBody>&& rigidBody)
{
	m_rigidBodyies.push_back(move(rigidBody));
	auto result = uwptr<RigidBody>(m_rigidBodyies.back());

	auto& attributes = result.lock()->getAttibutes();
	for (auto attribute : attributes)
		m_groupedRigidBodies[attribute].push_back(result);

	return result;
}

uwptr<RigidBody> hasel::cs2d::World::createRigidBody(const RigidBodyBuilder & builder)
{
	m_rigidBodyies.push_back(move(builder.buildUnique()));
	auto weak = uwptr<RigidBody>(m_rigidBodyies.back());

	auto& attributes = weak.lock()->getAttibutes();
	for (auto attribute : attributes)
		m_groupedRigidBodies[attribute].push_back(weak);
	return weak;
}

void hasel::cs2d::World::removeRigidBody(const uwptr<RigidBody>& target)
{
	auto& attributes = target.lock()->getAttibutes();
	for (auto attribute : attributes)
		m_groupedRigidBodies[attribute].remove(target);
	m_rigidBodyies.remove(target.lock());
}

const std::list<uptr<RigidBody>>& hasel::cs2d::World::getRigidBodies() const
{
	return m_rigidBodyies;
}

const std::list<uwptr<RigidBody>>& hasel::cs2d::World::getRigidBodies(int attribute) const
{
	return m_groupedRigidBodies.at(attribute);
}

uwptr<CollisionCallback> hasel::cs2d::World::addCollisionCallback(uptr<CollisionCallback>&& callback)
{
	auto result = uwptr<CollisionCallback>(callback);
	m_callbacks.push_back(move(callback));
	return result;
}

void hasel::cs2d::World::removeCollisionCallback(const uwptr<CollisionCallback>& target)
{
	m_callbacks.remove(target.lock());
}

void hasel::cs2d::World::executeCollision()
{
	for (auto& callback : m_callbacks)
	{
		for (auto& bodyA : m_groupedRigidBodies.at(callback->getAttributeA()))
		{
			for (auto& bodyB : m_groupedRigidBodies.at(callback->getAttributeB()))
			{
				bool isSame = bodyA.lock().get() == bodyB.lock().get();
				if (isSame)
					continue;

				bool isHitAABB = bodyA.lock()->getAABB().isIntersect(bodyB.lock()->getAABB());
				if (!isHitAABB)
					continue;

				bool isHitShapes = isCollisionRigidBody(bodyA.lock().get(), bodyB.lock().get());
				if (!isHitShapes)
					continue;

				auto& sameAttrCallbacks = callback->getCallbacks();

				for (auto& sameAttrCallback : sameAttrCallbacks)
				{
					sameAttrCallback(bodyA.lock(), bodyB.lock());
				}

			}
		}
	}
}
