#pragma once

#include"../Hasel/Math/Vector2/Vector2.h"

namespace hasel
{
	namespace shape
	{
		/**
		@brief AABB�N���X
		*/
		class AABB
		{
		private:
			//! ���S���W
			math::Vector2 m_centerPos;
			//! ��
			float m_width;
			//! ����
			float m_height;
		public:

		public:
			AABB() = default;
			
			/**
			@param centerPos ���S���W
			@param width ��
			@param height ����
			*/
			AABB(const math::Vector2& centerPos, float width, float height);

			/**
			@param lower �ŏ����W
			@param upper �ő���W
			*/
			AABB(const math::Vector2& lower, const math::Vector2& upper);

			~AABB() = default;

			/**
			@brief ���S���W�̎擾
			@return ���S���W
			*/
			const math::Vector2& getCenterPosition()const;

			/**
			@brief ���S���W�̐ݒ�
			@param centerPos ���S���W
			*/
			void setCenterPosition(const math::Vector2& centerPos);

			/**
			@brief ���̎擾
			@return ��
			*/
			float getWidth()const;

			/**
			@brief �����̎擾
			@return ����
			*/
			float getHeight()const;

			/**
			@brief ���̐ݒ�
			@param width ��
			*/
			void setWidth(float width);

			/**
			@brief �����̐ݒ�
			@param height ����
			*/
			void setHeight(float height);

			/**
			@brief AABB�̃T�C�Y�̐ݒ�
			@param width ��
			@param height ����
			*/
			void setSize(float width, float height);

			/**
			@brief �ő���W�̎擾
			@return �ő���W
			*/
			math::Vector2 getUpper()const;

			/**
			@brief �ŏ����W�̎擾
			@return �ŏ����W
			*/
			math::Vector2 getLower()const;

			/**
			@brief AABB��AABB�̐ڐG����
			@param aabb AABB
			*/
			bool isIntersect(const AABB& aabb)const;

			/**
			@brief 2��AABB����������
			@return ��������AABB
			*/
			static AABB merge(const AABB& aabb1, const AABB& aabb2);

			void dump()const;
		};
	}
}