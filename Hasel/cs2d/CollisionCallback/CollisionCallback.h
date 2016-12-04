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
		@brief CollisionCallbackビルダー
		*/
		class CollisionCallbackBuilder
		{
			friend class CollisionCallback;
		private:
			//! 衝突する剛体A
			int m_attributeA;
			//! 衝突する剛体B
			int m_attributeB;
			//! コールバックリスト
			std::vector<std::function<void(const uptr<RigidBody>& bodyA, const uptr<RigidBody>& bodyB)>> m_callbacks;

			/**
			@brief setCallbacks用末端ダミー関数
			*/
			void setCallbacks() { m_callbacks.clear(); }

		public:
			/**
			@param attributeA 衝突させる剛体の属性A
			@param attributeB 衝突させる剛体の属性B
			*/
			CollisionCallbackBuilder(int attributeA, int attributeB);

			/**
			@brief コールバックリストを設定する
			@param head,tails... コールバックリスト
			@note 以前にビルダーに設定されていたコールバックはクリアされる
			*/
			template<class Head=std::function<void(const uptr<RigidBody>&,const uptr<RigidBody>&)>,class... Tails>
			CollisionCallbackBuilder& setCallbacks(const Head& head, const Tails... tails)
			{
				setCallbacks(tails...);
				m_callbacks.push_back(head);
				return *this;
			}

			/**
			@brief コールバックを追加する
			@param callback 追加するコールバック
			*/
			CollisionCallbackBuilder& addCallbacks(std::function<void(const uptr<RigidBody>&, const uptr<RigidBody>&)> callback);

			/**
			@brief インスタンス作成関数(shared)
			*/
			sptr<CollisionCallback> buildShared();

			/**
			@brief インスタンス作成関数(unique)
			*/
			uptr<CollisionCallback> buildUnique();

			/**
			@brief インスタンス作成関数(raw)
			*/
			CollisionCallback* buildRaw();
		};

		/**
		@brief 衝突した時に呼ばれる処理を登録するクラス
		*/
		class CollisionCallback
		{
		private:
			//! 衝突する剛体の属性A
			int m_attributeA;
			//! 衝突する剛体の属性B
			int m_attributeB;
			//! コールバックリスト
			std::vector<std::function<void(const uptr<RigidBody>& bodyA, const uptr<RigidBody>& bodyB)>> m_callbacks;

		public:
			CollisionCallback(const CollisionCallbackBuilder& builder);

			/**
			@brief 属性A取得関数
			@return int 属性A
			*/
			int getAttributeA()const;

			/**
			@brief 属性B取得関数
			@return int 属性B
			*/
			int getAttributeB()const;

			/**
			@brief コールバックリスト取得関数
			@return コールバックリスト
			*/
			const std::vector<std::function<void(const uptr<RigidBody>& bodyA, const uptr<RigidBody>& bodyB)>>&
				getCallbacks()const;

		};

	}
}