#pragma once

#include"../Hasel/HaselAlias.h"

#include<functional>
#include<vector>

namespace hasel
{
	namespace cs2d
	{
		class RigidBody;

		/**
		@brief CollisionCallback�r���_�[
		*/
		class CollisionCallbackBuilder
		{
			friend class CollisionCallback;
		private:
			//! �Փ˂��鍄��A
			int m_attributeA;
			//! �Փ˂��鍄��B
			int m_attributeB;
			//! �R�[���o�b�N���X�g
			std::vector<std::function<void(const uptr<RigidBody>& bodyA, const uptr<RigidBody>& bodyB)>> m_callbacks;

			/**
			@brief setCallbacks�p���[�_�~�[�֐�
			*/
			void setCallbacks() { m_callbacks.clear(); }

		public:
			/**
			@param attributeA �Փ˂����鍄�̂̑���A
			@param attributeB �Փ˂����鍄�̂̑���B
			*/
			CollisionCallbackBuilder(int attributeA, int attributeB);

			/**
			@brief �R�[���o�b�N���X�g��ݒ肷��
			@param head,tails... �R�[���o�b�N���X�g
			@note �ȑO�Ƀr���_�[�ɐݒ肳��Ă����R�[���o�b�N�̓N���A�����
			*/
			template<class Head=std::function<void(const uptr<RigidBody>&,const uptr<RigidBody>&)>,class... Tails>
			CollisionCallbackBuilder& setCallbacks(const Head& head, const Tails... tails)
			{
				setCallbacks(tails...);
				m_callbacks.push_back(head);
				return *this;
			}

			/**
			@brief �R�[���o�b�N��ǉ�����
			@param callback �ǉ�����R�[���o�b�N
			*/
			CollisionCallbackBuilder& addCallbacks(std::function<void(const uptr<RigidBody>&, const uptr<RigidBody>&)> callback);

			/**
			@brief �C���X�^���X�쐬�֐�(shared)
			*/
			sptr<CollisionCallback> buildShared();

			/**
			@brief �C���X�^���X�쐬�֐�(unique)
			*/
			uptr<CollisionCallback> buildUnique();

			/**
			@brief �C���X�^���X�쐬�֐�(raw)
			*/
			CollisionCallback* buildRaw();
		};

		/**
		@brief �Փ˂������ɌĂ΂�鏈����o�^����N���X
		*/
		class CollisionCallback
		{
		private:
			//! �Փ˂��鍄�̂̑���A
			int m_attributeA;
			//! �Փ˂��鍄�̂̑���B
			int m_attributeB;
			//! �R�[���o�b�N���X�g
			std::vector<std::function<void(const uptr<RigidBody>& bodyA, const uptr<RigidBody>& bodyB)>> m_callbacks;

		public:
			CollisionCallback(const CollisionCallbackBuilder& builder);

			/**
			@brief ����A�擾�֐�
			@return int ����A
			*/
			int getAttributeA()const;

			/**
			@brief ����B�擾�֐�
			@return int ����B
			*/
			int getAttributeB()const;

			/**
			@brief �R�[���o�b�N���X�g�擾�֐�
			@return �R�[���o�b�N���X�g
			*/
			const std::vector<std::function<void(const uptr<RigidBody>& bodyA, const uptr<RigidBody>& bodyB)>>&
				getCallbacks()const;

		};

	}
}