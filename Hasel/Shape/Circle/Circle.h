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
		@brief �~�}�`�r���_�[
		*/
		class CircleBuilder
		{
			friend class Circle;
		private:
			//! �I�t�Z�b�g���W
			hasel::math::Vector2 m_offset;
			//! �~�̔��a
			float m_radius;

		public:
			/**
			@param radius �~�̔��a
			@note ���̃R���X�g���N�^��Circle�N���X�K�{�p�����[�^�����
			*/
			CircleBuilder(float radius);

			/**
			@brief �I�v�V����:�I�t�Z�b�g���W�̐ݒ�
			@param offset �I�t�Z�b�g���W
			*/
			CircleBuilder* setOffset(const hasel::math::Vector2& offset);

			/**
			@brief �~�C���X�^���X�쐬�֐�(shared)
			@return sptr<Circle> �C���X�^���X
			*/
			sptr<Circle> buildShared();

			/**
			@brief �~�C���X�^���X�쐬�֐�(unique)
			*/
			uptr<Circle> buildUnique();

			/**
			@brief �~�C���X�^���X�쐬�֐�(raw)
			@retun Circle �C���X�^���X
			*/
			Circle* buildRaw();
		};

		/**
		@brief �~�N���X
		*/
		class Circle :public Shape
		{
		private:
			//! �~�̔��a
			float m_radius;

		public:
			/**
			@param builder �~�r���_�[
			*/
			Circle(const CircleBuilder& builder);

			Circle(const Circle&) = default;

			Circle* clone()const { return new Circle(*this); }

			/**
			@brief �~�̔��a��ݒ�
			@param radius �~�̔��a
			*/
			void setRadius(float radius);

			/**
			@brief �~�̔��a���擾
			@return �~�̔��a
			*/
			float getRadius()const;
		};
	}
}