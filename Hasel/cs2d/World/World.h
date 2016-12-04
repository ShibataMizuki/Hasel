#pragma once

#include"../Hasel/Math/MathInc.h"
#include"../Hasel/HaselAlias.h"

#include<map>
#include<list>

namespace hasel
{
	namespace shape
	{
		class Shape;
	}

	namespace cs2d
	{
		class RigidBody;
		class CollisionCallback;
		class RigidBodyBuilder;

		/**
		@brief World�̃r���_�[
		*/
		class WorldBuilder
		{
			friend class World;
		private:

		public:
			/**
			@brief �C���X�^���X�쐬�֐�(shared)
			@return World�̃C���X�^���X(shared)
			*/
			sptr<World> buildShared();
			
			/**
			@brief �C���X�^���X�쐬�֐�(unique)
			@return World�̃C���X�^���X(unique)
			*/
			uptr<World> buildUnique();

			/**
			@brief �C���X�^���X�쐬�֐�(raw)
			@return World�̃C���X�^���X(raw)
			*/
			World* buildRaw();
		};

		/**
		@brief ���̂̏Փˏ������s���N���X
		*/
		class World
		{
		private:
			//! ���̃��X�g
			std::list<uptr<RigidBody>> m_rigidBodyies;
			//! �����O���[�s���O�ςݍ��̃��X�g map<���̂̑���,����>
			std::map<int, std::list<uwptr<RigidBody>>> m_groupedRigidBodies;
			//! �R�[���o�b�N���X�g
			std::list<uptr<CollisionCallback>> m_callbacks;

			/**

			*/
			bool isCollisionRigidBody(RigidBody* bodyA, RigidBody* bodyB);

		public:
			/**
			@param builder �r���_�[
			*/
			World(const WorldBuilder& builder);

			/**
			@brief ���̂�ǉ�����
			@param rigidBody �ǉ����鍄��
			@return unique_ptr�p��Q�ƃN���X
			@note ���̂̏��L����World������
			*/
			uwptr<RigidBody> addRigidBody(uptr<RigidBody>&& rigidBody);

			/**
			@brief ���̂��쐬����
			@param builder ���̂̃r���_�[
			@return unique_ptr�p��Q�ƃN���X
			*/
			uwptr<RigidBody> createRigidBody(const RigidBodyBuilder& builder);

			/**
			@brief ���̂��폜����
			@param target �폜���鍄��
			*/
			void removeRigidBody(const uwptr<RigidBody>& target);

			/**
			@brief ���̃��X�g���擾����
			@return ���̃��X�g
			*/
			const std::list<uptr<RigidBody>>& getRigidBodies()const;

			/**
			@brief ���̃��X�g���擾����
			@param attribute �擾���鍄�̂̑���
			@return ���̃��X�g
			*/
			const std::list<uwptr<RigidBody>>& getRigidBodies(int attribute)const;

			/**
			@brief �Փ˃R�[���o�b�N��ǉ�����
			@param callback �ǉ�����R�[���o�b�N
			@return unique_ptr�p��Q�ƃN���X
			@note �R�[���o�b�N�̏��L����World������
			*/
			uwptr<CollisionCallback> addCollisionCallback(uptr<CollisionCallback>&& callback);

			/**
			@brief �Փ˃R�[���o�b�N���폜����
			@param target �폜����R�[���o�b�N
			*/
			void removeCollisionCallback(const uwptr<CollisionCallback>& target);

			/**
			@brief �Փ˂̌��m�y�уR�[���o�b�N�֐��̌Ăяo�����s��
			@note ���ʂȂ��Ƃ��Ȃ����薈�t���[���Ă�
			*/
			void executeCollision();
		};
	}
}