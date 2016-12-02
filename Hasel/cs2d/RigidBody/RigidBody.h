#pragma once
#include"Hasel/HaselAlias.h"
#include"Hasel/Math/MathInc.h"
#include"Hasel/Shape/AABB/AABB.h"

#include<memory>
#include<vector>

namespace hasel
{
	namespace shape
	{
		class Shape;
		class Circle;
	}

	namespace cs2d
	{
		/**
		@brief RigidBody�r���_�[
		*/
		class RigidBodyBuilder
		{
			friend class RigidBody;
		private:
			//! �}�`���X�g
			std::vector<const shape::Shape*> m_shapes;
			//! �������X�g
			std::vector<int> m_attributes;
			//! ���[�U�[�f�[�^
			void* m_userdata;
			//! ���W
			math::Vector2 m_pos;

			/**
			@brief �}�`���X�g�ݒ�p�̖��[�_�~�[�֐�
			*/
			void setShapes() { m_shapes.clear(); }
			/**
			@brief �������X�g�ݒ�p�̖��[�_�~�[�֐�
			*/
			void setAttributes() { m_attributes.clear();}

			//RigidBodyBuilder(const RigidBodyBuilder&);
			//void operator=(const RigidBodyBuilder&);
		public:
			RigidBodyBuilder();

			/**
			@brief ���W�ݒ�֐�
			@param pos �ݒ肷����W
			*/
			RigidBodyBuilder& setPosition(const math::Vector2& pos);

			/**
			@brief �`�󃊃X�g�ݒ�֐�
			@param head,tails... �ݒ肷��`�󃊃X�g
			@note �ݒ肷��O�̌`�󃊃X�g�̓N���A�����
			*/
			template<class Head = shape::Shape, class... Tails>
			RigidBodyBuilder& setShapes(const Head& head, const Tails&... tails)
			{
				setShapes(tails...);
				m_shapes.push_back(head);
				return *this;
			}

			/**
			@brief �`���ǉ�����
			@param shape �ǉ�����`��
			*/
			RigidBodyBuilder& addShape(const shape::Shape* shape);

			/**
			@brief �������X�g�ݒ�֐�
			@param head,tails... �ݒ肷�鑮�����X�g
			@note �ݒ肷��O�̑������X�g�̓N���A�����
			*/
			template<class Head = int, class... Tails>
			RigidBodyBuilder& setAttributes(const Head& head,const Tails&... tails)
			{
				setAttributes(tails...);
				m_attributes.push_back(head);
				return *this;
			}

			/**
			@brief ������ǉ�����
			@param attribute �ǉ����鑮��
			*/
			RigidBodyBuilder& addAttribute(int attribute);

			/**
			@brief ���[�U�[�f�[�^�ݒ�֐�
			@param userdata �ݒ肷�郆�[�U�[�f�[�^
			*/
			RigidBodyBuilder& setUserdata(void* userdata);

			/**
			@brief �C���X�^���X�쐬�֐�(shared)
			@return sptr<RigidBody> �쐬���ꂽ����
			*/
			sptr<RigidBody> buildShared();

			/**
			@brief �C���X�^���X�쐬�֐�(unique)
			@return uptr<RigidBody> �쐬���ꂽ����
			*/
			uptr<RigidBody> buildUnique();

			/**
			@brief �C���X�^���X�쐬�֐�(raw)
			@return RigidBody* �쐬���ꂽ����
			*/
			RigidBody* buildRaw();
		};

		/**
		@brief ���̃N���X
		*/
		class RigidBody
		{
		private:
			//! ���W
			math::Vector2 m_pos;
			//! �}�`���X�g
			std::vector<uptr<shape::Shape>> m_shapes;
			//! �������X�g
			std::vector<int> m_attributes;
			//! ���[�U�[�f�[�^
			void* m_userdata;
			//! AABB
			shape::AABB m_aabb;
			//! AABB���ύX���ꂽ�\�������邩�ǂ���
			bool m_isAABBChanged;

		public:
			/**
			@param builder RigidBody�r���_�[
			*/
			RigidBody(const RigidBodyBuilder& builder);

			/**
			@brief ���W�̐ݒ�֐�
			@param pos ���W
			*/
			void setPosition(const math::Vector2& pos);

			/**
			@brief ���W�̎擾�֐�
			@return Vector2 ���W
			*/
			const math::Vector2& getPosition()const;

			/**
			@brief ������ǉ�����
			@param attribute �ǉ����鑮��
			*/
			void addAttribute(int attribute);

			/**
			@brief �������폜����
			@param attribute �폜���鑮��
			*/
			void removeAttribute(int attribute);

			/**
			@brief ���������݂��邩�ǂ����T��
			@param attribute �T������
			@return true  :���݂���
					false :���݂��Ȃ�
			*/
			bool findAttribute(int attribute)const;

			/**
			@brief �������X�g�擾�֐�
			@return vector<int> �������X�g
			*/
			const std::vector<int>& getAttibutes()const;

			/**
			@brief ���[�U�[�f�[�^�ݒ�֐�
			@param userdata ���[�U�[�f�[�^
			*/
			void setUserdata(void* userdata);

			/**
			@brief ���[�U�[�f�[�^(void*)���擾
			@return void* ���[�U�[�f�[�^
			*/
			void* getUserdataRaw()const;

			/**
			@brief ���[�U�[�f�[�^���擾
			@return Type* ���[�U�[�f�[�^
			*/
			template<typename Type>
			Type* getUserdata()const
			{
				return static_cast<Type*>(m_userdata);
			}

			/**
			@brief AABB�擾�֐�
			@return AABB AABB
			*/
			const shape::AABB& getAABB();

			/**
			@brief �}�`���X�g�擾�֐�
			@return �}�`���X�g
			*/
			const std::vector<uptr<shape::Shape>>& getShapes()const;

		};
	}
}