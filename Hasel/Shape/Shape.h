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
			//! �I�t�Z�b�g
			hasel::math::Vector2 m_offset;
			//! AABB
			AABB m_aabb;

		public:
			Shape() = default;
			Shape(const Shape&) = default;
			virtual ~Shape() = default;

			virtual Shape* clone()const { return new Shape(*this); }

			/**
			@param offset �I�t�Z�b�g
			*/
			Shape(const hasel::math::Vector2& offset) :m_offset(offset) {}

			/**
			@brief �I�t�Z�b�g�ݒ�֐�
			@param offset �ݒ肷��I�t�Z�b�g
			*/
			void setOffset(const hasel::math::Vector2& offset);

			/**
			@brief �I�t�Z�b�g�擾�֐�
			@return Vector2 �I�t�Z�b�g
			*/
			const hasel::math::Vector2& getOffset()const;

			/**
			@brief �}�`������AABB���擾
			@return AABB
			*/
			const AABB& getAABB()const;
		};
	}
}