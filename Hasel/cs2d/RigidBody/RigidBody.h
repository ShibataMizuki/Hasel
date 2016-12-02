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
		@brief RigidBodyビルダー
		*/
		class RigidBodyBuilder
		{
			friend class RigidBody;
		private:
			//! 図形リスト
			std::vector<const shape::Shape*> m_shapes;
			//! 属性リスト
			std::vector<int> m_attributes;
			//! ユーザーデータ
			void* m_userdata;
			//! 座標
			math::Vector2 m_pos;

			/**
			@brief 図形リスト設定用の末端ダミー関数
			*/
			void setShapes() { m_shapes.clear(); }
			/**
			@brief 属性リスト設定用の末端ダミー関数
			*/
			void setAttributes() { m_attributes.clear();}

			//RigidBodyBuilder(const RigidBodyBuilder&);
			//void operator=(const RigidBodyBuilder&);
		public:
			RigidBodyBuilder();

			/**
			@brief 座標設定関数
			@param pos 設定する座標
			*/
			RigidBodyBuilder& setPosition(const math::Vector2& pos);

			/**
			@brief 形状リスト設定関数
			@param head,tails... 設定する形状リスト
			@note 設定する前の形状リストはクリアされる
			*/
			template<class Head = shape::Shape, class... Tails>
			RigidBodyBuilder& setShapes(const Head& head, const Tails&... tails)
			{
				setShapes(tails...);
				m_shapes.push_back(head);
				return *this;
			}

			/**
			@brief 形状を追加する
			@param shape 追加する形状
			*/
			RigidBodyBuilder& addShape(const shape::Shape* shape);

			/**
			@brief 属性リスト設定関数
			@param head,tails... 設定する属性リスト
			@note 設定する前の属性リストはクリアされる
			*/
			template<class Head = int, class... Tails>
			RigidBodyBuilder& setAttributes(const Head& head,const Tails&... tails)
			{
				setAttributes(tails...);
				m_attributes.push_back(head);
				return *this;
			}

			/**
			@brief 属性を追加する
			@param attribute 追加する属性
			*/
			RigidBodyBuilder& addAttribute(int attribute);

			/**
			@brief ユーザーデータ設定関数
			@param userdata 設定するユーザーデータ
			*/
			RigidBodyBuilder& setUserdata(void* userdata);

			/**
			@brief インスタンス作成関数(shared)
			@return sptr<RigidBody> 作成された剛体
			*/
			sptr<RigidBody> buildShared();

			/**
			@brief インスタンス作成関数(unique)
			@return uptr<RigidBody> 作成された剛体
			*/
			uptr<RigidBody> buildUnique();

			/**
			@brief インスタンス作成関数(raw)
			@return RigidBody* 作成された剛体
			*/
			RigidBody* buildRaw();
		};

		/**
		@brief 剛体クラス
		*/
		class RigidBody
		{
		private:
			//! 座標
			math::Vector2 m_pos;
			//! 図形リスト
			std::vector<uptr<shape::Shape>> m_shapes;
			//! 属性リスト
			std::vector<int> m_attributes;
			//! ユーザーデータ
			void* m_userdata;
			//! AABB
			shape::AABB m_aabb;
			//! AABBが変更された可能性があるかどうか
			bool m_isAABBChanged;

		public:
			/**
			@param builder RigidBodyビルダー
			*/
			RigidBody(const RigidBodyBuilder& builder);

			/**
			@brief 座標の設定関数
			@param pos 座標
			*/
			void setPosition(const math::Vector2& pos);

			/**
			@brief 座標の取得関数
			@return Vector2 座標
			*/
			const math::Vector2& getPosition()const;

			/**
			@brief 属性を追加する
			@param attribute 追加する属性
			*/
			void addAttribute(int attribute);

			/**
			@brief 属性を削除する
			@param attribute 削除する属性
			*/
			void removeAttribute(int attribute);

			/**
			@brief 属性が存在するかどうか探す
			@param attribute 探す属性
			@return true  :存在する
					false :存在しない
			*/
			bool findAttribute(int attribute)const;

			/**
			@brief 属性リスト取得関数
			@return vector<int> 属性リスト
			*/
			const std::vector<int>& getAttibutes()const;

			/**
			@brief ユーザーデータ設定関数
			@param userdata ユーザーデータ
			*/
			void setUserdata(void* userdata);

			/**
			@brief ユーザーデータ(void*)を取得
			@return void* ユーザーデータ
			*/
			void* getUserdataRaw()const;

			/**
			@brief ユーザーデータを取得
			@return Type* ユーザーデータ
			*/
			template<typename Type>
			Type* getUserdata()const
			{
				return static_cast<Type*>(m_userdata);
			}

			/**
			@brief AABB取得関数
			@return AABB AABB
			*/
			const shape::AABB& getAABB();

			/**
			@brief 図形リスト取得関数
			@return 図形リスト
			*/
			const std::vector<uptr<shape::Shape>>& getShapes()const;

		};
	}
}