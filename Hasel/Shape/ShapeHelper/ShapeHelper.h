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
		@brief 図形用補助クラス
		*/
		class ShapeHelper
		{
		public:
			/**
			@brief 2つのAABBを合成したAABBを作成する
			@param lhs 合成するAABBその1
			@param rhs 合成するAABBその2
			@return AABB 合成されたAABB
			*/
			static AABB mergeAABB(const AABB& lhs, const AABB& rhs);

			/**
			@brief 複数の図形から、それを内包するAABBを作成する
			@param shapes 図形リスト
			@param pos オブジェクトの座標
			@return AABB 作成されたAABB
			*/
			static AABB createAABBFromShapes(const std::vector<Shape>& shapes, const hasel::math::Vector2& pos);

			/**
			@brief 複数の図形から、それを内包するAABBを作成する
			@param shapes 図形リスト
			@param pos オブジェクトの座標
			@return AABB 作成されたAABB
			*/
			static AABB createAABBFromShapes(const std::vector<sptr<Shape>>& shapes, const hasel::math::Vector2& pos);

			/**
			@brief 複数の図形から、それを内包するAABBを作成する
			@param shapes 図形リスト
			@param pos オブジェクトの座標
			@return AABB 作成されたAABB
			*/
			static AABB createAABBFromShapes(const std::vector<uptr<Shape>>& shapes, const hasel::math::Vector2& pos);
		};
	}
}