#pragma once

#include"Hasel/Math/MathInc.h"

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
		@brief Õ“Ë•â•ƒNƒ‰ƒX
		*/
		class CollisionHelper
		{
		public:
			/**
			@brief }Œ`“¯m‚ÌŒğ·”»’è
			@param shapeA ”»’è‚·‚é}Œ`A
			@param shapeB ”»’è‚·‚é}Œ`B
			@param posA ”»’è‚·‚é}Œ`A‚ÌÀ•W
			@param posB ”»’è‚·‚é}Œ`B‚ÌÀ•W
			@return Œğ·‚µ‚½‚©‚Ç‚¤‚©
			*/
			static bool isIntersect(shape::Shape* shapeA, shape::Shape* shapeB, 
				const math::Vector2& posA, const math::Vector2& posB);

			/**
			@brief ‰~“¯m‚ÌŒğ·”»’è
			@param circleA ”»’è‚·‚é‰~}Œ`A
			@param cirlceB ”»’è‚·‚é‰~}Œ`B
			@param posA ”»’è‚·‚é‰~}Œ`A‚ÌÀ•W
			@param posB ”»’è‚·‚é‰~}Œ`B‚ÌÀ•W
			@return Œğ·‚µ‚½‚©‚Ç‚¤‚©
			*/
			static bool isIntersectCircle(shape::Circle* circleA, shape::Circle* circleB, 
				const math::Vector2& posA, const math::Vector2& posB);
		};
	}
}