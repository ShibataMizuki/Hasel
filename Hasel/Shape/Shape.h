#pragma once

#include"../Hasel/Math/Vector2/Vector2.h"
#include"AABB/AABB.h"

namespace hasel
{
	namespace shape
	{
		class Shape
		{
		protected:
			//! オフセット
			hasel::math::Vector2 m_offset;
			//! AABB
			AABB m_aabb;

		public:
			Shape() = default;
			Shape(const Shape&) = default;
			virtual ~Shape() = default;

			virtual Shape* clone()const { return new Shape(*this); }

			/**
			@param offset オフセット
			*/
			Shape(const hasel::math::Vector2& offset) :m_offset(offset) {}

			/**
			@brief オフセット設定関数
			@param offset 設定するオフセット
			*/
			void setOffset(const hasel::math::Vector2& offset);

			/**
			@brief オフセット取得関数
			@return Vector2 オフセット
			*/
			const hasel::math::Vector2& getOffset()const;

			/**
			@brief 図形を内包するAABBを取得
			@return AABB
			*/
			const AABB& getAABB()const;
		};
	}
}