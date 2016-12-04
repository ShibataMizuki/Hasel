#include "RigidBody.h"

#include"../Hasel/Hasel.h"
#include<algorithm>

using namespace hasel;
using namespace hasel::algo;
using namespace hasel::cs2d;
using namespace hasel::shape;
using namespace hasel::math;
using namespace std;

RigidBodyBuilder::RigidBodyBuilder()
{
}

RigidBodyBuilder& RigidBodyBuilder::setPosition(const Vector2 & pos)
{
	m_pos = pos;
	return *this;
}

RigidBodyBuilder& RigidBodyBuilder::addShape(const Shape* shape)
{
	m_shapes.push_back(shape);
	return *this;
}

RigidBodyBuilder& RigidBodyBuilder::addAttribute(int attribute)
{
	m_attributes.push_back(attribute);
	return *this;
}

RigidBodyBuilder& RigidBodyBuilder::setUserdata(void * userdata)
{
	m_userdata = userdata;
	return *this;
}

sptr<RigidBody> RigidBodyBuilder::buildShared()const
{
	return move(make_shared<RigidBody>(*this));
}

uptr<RigidBody> hasel::cs2d::RigidBodyBuilder::buildUnique()const
{
	return move(make_unique<RigidBody>(*this));
}

RigidBody * RigidBodyBuilder::buildRaw()const
{
	return new RigidBody(*this);
}

RigidBody::RigidBody(const RigidBodyBuilder & builder)
{
	m_pos = builder.m_pos;

	m_shapes.resize(builder.m_shapes.size());
	int count = 0;
	for (auto shape : builder.m_shapes)
	{
		auto clone = shape->clone();
		m_shapes[count] = move(hasel::uptr<Shape>(clone));
		count++;
	}

	m_attributes = builder.m_attributes;
	m_userdata = builder.m_userdata;

	m_aabb = ShapeHelper::createAABBFromShapes(m_shapes, m_pos);

	m_isAABBChanged = false;
}

void hasel::cs2d::RigidBody::setPosition(const Vector2 & pos)
{
	m_pos = pos;
	m_isAABBChanged = true;
}

const Vector2 & hasel::cs2d::RigidBody::getPosition() const
{
	return m_pos;
}

void hasel::cs2d::RigidBody::addAttribute(int attribute)
{
	m_attributes.push_back(attribute);
}

void hasel::cs2d::RigidBody::removeAttribute(int attribute)
{
	auto target = find(m_attributes.begin(), m_attributes.end(), attribute);
	m_attributes.erase(target);
}

bool hasel::cs2d::RigidBody::findAttribute(int attribute) const
{
	auto target = find(m_attributes.begin(), m_attributes.end(), attribute);
	return target != m_attributes.end();
}

const std::vector<int>& hasel::cs2d::RigidBody::getAttibutes() const
{
	return m_attributes;
}

void hasel::cs2d::RigidBody::setUserdata(void * userdata)
{
	m_userdata = userdata;
}

void * hasel::cs2d::RigidBody::getUserdataRaw() const
{
	return m_userdata;
}

const AABB& RigidBody::getAABB()
{
	if (!m_isAABBChanged)
		return m_aabb;

	m_aabb = ShapeHelper::createAABBFromShapes(m_shapes, m_pos);
	m_isAABBChanged = false;
	return m_aabb;
}

const std::vector<uptr<shape::Shape>>& hasel::cs2d::RigidBody::getShapes() const
{
	return m_shapes;
}
