#pragma once

#include<string>

namespace hasel
{
	namespace math
	{
		class Vector2
		{
		public:
			//! X�v�f,Y�v�f
			float x, y;

			/*==============================
			�R���X�g���N�^
			===============================*/
			Vector2();
			Vector2(float x, float y);

			/*==============================
			�I�y���[�^�̃I�[�o�[���[�h
			===============================*/
			Vector2 operator+(const Vector2& rv)const;
			Vector2 operator-(const Vector2& rv)const;
			Vector2 operator*(float rv)const;
			Vector2 operator/(float rv)const;
			void operator+=(const Vector2& rv);
			void operator-=(const Vector2& rv);

			/*==============================
			���̑��֐�
			===============================*/
			//! �x�N�g���̒������Z�o
			float getLength()const;
			//! �x�N�g���𐳋K��
			void normalize();
			//! ���K�������x�N�g�����擾
			Vector2 getNormalized()const;
			//! �x�N�g���̓���
			float dot(const Vector2& rv)const;
			//! �x�N�g���̊O��
			float cross(const Vector2& rv)const;

			////////////////////////////////////////
			//! �x�N�g���̒��𔻒�
			static constexpr bool isOrthogonal(const Vector2& lv, const Vector2& rv);
			//! �x�N�g���̕��s����
			static constexpr bool isParallel(const Vector2& lv, const Vector2& rv);

			//! @brief �_���v��������擾
			std::string dump()const;
		};
	}
}