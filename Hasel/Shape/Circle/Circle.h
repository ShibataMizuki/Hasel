#pragma once

#include"../Hasel/Shape/Shape.h"
#include"../Hasel/HaselAlias.h"
#include"../Hasel/Math/MathInc.h"

#include<memory>

namespace hasel
{
	namespace shape
	{
		/**
		@brief 円図形ビルダー
		*/
		class CircleBuilder
		{
			friend class Circle;
		private:
			//! オフセット座標
			hasel::math::Vector2 m_offset;
			//! 円の半径
			float m_radius;

		public:
			/**
			@param radius 円の半径
			@note このコンストラクタはCircleクラス必須パラメータを取る
			*/
			CircleBuilder(float radius);

			/**
			@brief オプション:オフセット座標の設定
			@param offset オフセット座標
			*/
			CircleBuilder* setOffset(const hasel::math::Vector2& offset);

			/**
			@brief 円インスタンス作成関数(shared)
			@return sptr<Circle> インスタンス
			*/
			sptr<Circle> buildShared();

			/**
			@brief 円インスタンス作成関数(unique)
			*/
			uptr<Circle> buildUnique();

			/**
			@brief 円インスタンス作成関数(raw)
			@retun Circle インスタンス
			*/
			Circle* buildRaw();
		};

		/**
		@brief 円クラス
		*/
		class Circle :public Shape
		{
		private:
			//! 円の半径
			float m_radius;

		public:
			/**
			@param builder 円ビルダー
			*/
			Circle(const CircleBuilder& builder);

			Circle(const Circle&) = default;

			Circle* clone()const { return new Circle(*this); }

			/**
			@brief 円の半径を設定
			@param radius 円の半径
			*/
			void setRadius(float radius);

			/**
			@brief 円の半径を取得
			@return 円の半径
			*/
			float getRadius()const;
		};
	}
}