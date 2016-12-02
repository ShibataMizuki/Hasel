#pragma once

#include"Hasel/HaselAlias.h"
#include"Hasel/Math/MathInc.h"
#include"Hasel/Shape/AABB/AABB.h"
#include"hasel/Shape/Shape.h"

#include<algorithm>
#include<vector>

namespace hasel
{
	namespace shape
	{
		/**
		@brief �}�`�p�⏕�N���X
		*/
		class ShapeHelper
		{
		public:
			/**
			@brief 2��AABB����������AABB���쐬����
			@param lhs ��������AABB����1
			@param rhs ��������AABB����2
			@return AABB �������ꂽAABB
			*/
			static AABB mergeAABB(const AABB& lhs, const AABB& rhs);

			/**
			@brief �����̐}�`����A���������AABB���쐬����
			@param shapes �}�`���X�g
			@param pos �I�u�W�F�N�g�̍��W
			@return AABB �쐬���ꂽAABB
			*/
			static AABB createAABBFromShapes(const std::vector<Shape>& shapes, const hasel::math::Vector2& pos);

			/**
			@brief �����̐}�`����A���������AABB���쐬����
			@param shapes �}�`���X�g
			@param pos �I�u�W�F�N�g�̍��W
			@return AABB �쐬���ꂽAABB
			*/
			static AABB createAABBFromShapes(const std::vector<sptr<Shape>>& shapes, const hasel::math::Vector2& pos);

			/**
			@brief �����̐}�`����A���������AABB���쐬����
			@param shapes �}�`���X�g
			@param pos �I�u�W�F�N�g�̍��W
			@return AABB �쐬���ꂽAABB
			*/
			static AABB createAABBFromShapes(const std::vector<uptr<Shape>>& shapes, const hasel::math::Vector2& pos);
		};
	}
}