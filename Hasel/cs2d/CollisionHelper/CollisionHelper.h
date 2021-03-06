#pragma once

#include"../Hasel/Math/MathInc.h"

namespace hasel
{
	namespace shape
	{
		class Shape;
		class Circle;
	}

	namespace cs2d
	{
		/**
		@brief 衝突補助クラス
		*/
		class CollisionHelper
		{
		public:
			/**
			@brief 図形同士の交差判定
			@param shapeA 判定する図形A
			@param shapeB 判定する図形B
			@param posA 判定する図形Aの座標
			@param posB 判定する図形Bの座標
			@return 交差したかどうか
			*/
			static bool isIntersect(shape::Shape* shapeA, shape::Shape* shapeB, 
				const math::Vector2& posA, const math::Vector2& posB);

			/**
			@brief 円同士の交差判定
			@param circleA 判定する円図形A
			@param cirlceB 判定する円図形B
			@param posA 判定する円図形Aの座標
			@param posB 判定する円図形Bの座標
			@return 交差したかどうか
			*/
			static bool isIntersectCircle(shape::Circle* circleA, shape::Circle* circleB, 
				const math::Vector2& posA, const math::Vector2& posB);
		};
	}
}