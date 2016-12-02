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
		@brief �Փ˕⏕�N���X
		*/
		class CollisionHelper
		{
		public:
			/**
			@brief �}�`���m�̌�������
			@param shapeA ���肷��}�`A
			@param shapeB ���肷��}�`B
			@param posA ���肷��}�`A�̍��W
			@param posB ���肷��}�`B�̍��W
			@return �����������ǂ���
			*/
			static bool isIntersect(shape::Shape* shapeA, shape::Shape* shapeB, 
				const math::Vector2& posA, const math::Vector2& posB);

			/**
			@brief �~���m�̌�������
			@param circleA ���肷��~�}�`A
			@param cirlceB ���肷��~�}�`B
			@param posA ���肷��~�}�`A�̍��W
			@param posB ���肷��~�}�`B�̍��W
			@return �����������ǂ���
			*/
			static bool isIntersectCircle(shape::Circle* circleA, shape::Circle* circleB, 
				const math::Vector2& posA, const math::Vector2& posB);
		};
	}
}