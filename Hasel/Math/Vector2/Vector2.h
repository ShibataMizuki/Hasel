#pragma once

#include<string>

namespace hasel
{
	namespace math
	{
		class Vector2
		{
		public:
			//! X要素,Y要素
			float x, y;

			/*==============================
			コンストラクタ
			===============================*/
			Vector2();
			Vector2(float x, float y);

			/*==============================
			オペレータのオーバーロード
			===============================*/
			Vector2 operator+(const Vector2& rv)const;
			Vector2 operator-(const Vector2& rv)const;
			Vector2 operator*(float rv)const;
			Vector2 operator/(float rv)const;
			void operator+=(const Vector2& rv);
			void operator-=(const Vector2& rv);

			/*==============================
			その他関数
			===============================*/
			//! ベクトルの長さを算出
			float getLength()const;
			//! ベクトルを正規化
			void normalize();
			//! 正規化したベクトルを取得
			Vector2 getNormalized()const;
			//! ベクトルの内積
			float dot(const Vector2& rv)const;
			//! ベクトルの外積
			float cross(const Vector2& rv)const;

			////////////////////////////////////////
			//! ベクトルの直交判定
			static constexpr bool isOrthogonal(const Vector2& lv, const Vector2& rv);
			//! ベクトルの平行判定
			static constexpr bool isParallel(const Vector2& lv, const Vector2& rv);

			//! @brief ダンプ文字列を取得
			std::string dump()const;
		};
	}
}