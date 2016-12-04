#pragma once

#include"../Hasel/Math/Vector2/Vector2.h"

namespace hasel
{
	namespace shape
	{
		/**
		@brief AABBクラス
		*/
		class AABB
		{
		private:
			//! 中心座標
			math::Vector2 m_centerPos;
			//! 幅
			float m_width;
			//! 高さ
			float m_height;
		public:

		public:
			AABB() = default;
			
			/**
			@param centerPos 中心座標
			@param width 幅
			@param height 高さ
			*/
			AABB(const math::Vector2& centerPos, float width, float height);

			/**
			@param lower 最小座標
			@param upper 最大座標
			*/
			AABB(const math::Vector2& lower, const math::Vector2& upper);

			~AABB() = default;

			/**
			@brief 中心座標の取得
			@return 中心座標
			*/
			const math::Vector2& getCenterPosition()const;

			/**
			@brief 中心座標の設定
			@param centerPos 中心座標
			*/
			void setCenterPosition(const math::Vector2& centerPos);

			/**
			@brief 幅の取得
			@return 幅
			*/
			float getWidth()const;

			/**
			@brief 高さの取得
			@return 高さ
			*/
			float getHeight()const;

			/**
			@brief 幅の設定
			@param width 幅
			*/
			void setWidth(float width);

			/**
			@brief 高さの設定
			@param height 高さ
			*/
			void setHeight(float height);

			/**
			@brief AABBのサイズの設定
			@param width 幅
			@param height 高さ
			*/
			void setSize(float width, float height);

			/**
			@brief 最大座標の取得
			@return 最大座標
			*/
			math::Vector2 getUpper()const;

			/**
			@brief 最小座標の取得
			@return 最小座標
			*/
			math::Vector2 getLower()const;

			/**
			@brief AABBとAABBの接触判定
			@param aabb AABB
			*/
			bool isIntersect(const AABB& aabb)const;

			/**
			@brief 2つのAABBを合成する
			@return 合成したAABB
			*/
			static AABB merge(const AABB& aabb1, const AABB& aabb2);

			void dump()const;
		};
	}
}