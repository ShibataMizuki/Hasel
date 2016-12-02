#pragma once

namespace hasel
{
	namespace math
	{
		class MathHelper
		{
		public:
			//! 円周率
			static constexpr float PI = 3.1415926f;
			static constexpr float HalfPIDeg = 180.f;

			/**
			@brief radian->degreeの変換
			@param rad radian値
			@return float degree値
			*/
			float toDegree(float rad) { return rad / (PI / HalfPIDeg); }
			/**
			@brief degree->radianの変換
			@param deg degree値
			@return float radian値
			*/
			float toRadian(float deg) { return deg*(PI / HalfPIDeg); }
		};
	}
}