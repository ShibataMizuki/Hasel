#pragma once

namespace hasel
{
	namespace math
	{
		class MathHelper
		{
		public:
			//! �~����
			static constexpr float PI = 3.1415926f;
			static constexpr float HalfPIDeg = 180.f;

			/**
			@brief radian->degree�̕ϊ�
			@param rad radian�l
			@return float degree�l
			*/
			float toDegree(float rad) { return rad / (PI / HalfPIDeg); }
			/**
			@brief degree->radian�̕ϊ�
			@param deg degree�l
			@return float radian�l
			*/
			float toRadian(float deg) { return deg*(PI / HalfPIDeg); }
		};
	}
}