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
		@brief Worldのビルダー
		*/
		class WorldBuilder
		{
			friend class World;
		private:

		public:
			/**
			@brief インスタンス作成関数(shared)
			@return Worldのインスタンス(shared)
			*/
			sptr<World> buildShared();
			
			/**
			@brief インスタンス作成関数(unique)
			@return Worldのインスタンス(unique)
			*/
			uptr<World> buildUnique();

			/**
			@brief インスタンス作成関数(raw)
			@return Worldのインスタンス(raw)
			*/
			World* buildRaw();
		};

		/**
		@brief 剛体の衝突処理を行うクラス
		*/
		class World
		{
		private:
			//! 剛体リスト
			std::list<uptr<RigidBody>> m_rigidBodyies;
			//! 属性グルーピング済み剛体リスト map<剛体の属性,剛体>
			std::map<int, std::list<uwptr<RigidBody>>> m_groupedRigidBodies;
			//! コールバックリスト
			std::list<uptr<CollisionCallback>> m_callbacks;

			/**

			*/
			bool isCollisionRigidBody(RigidBody* bodyA, RigidBody* bodyB);

		public:
			/**
			@param builder ビルダー
			*/
			World(const WorldBuilder& builder);

			/**
			@brief 剛体を追加する
			@param rigidBody 追加する剛体
			@return unique_ptr用弱参照クラス
			@note 剛体の所有権はWorldが持つ
			*/
			uwptr<RigidBody> addRigidBody(uptr<RigidBody>&& rigidBody);

			/**
			@brief 剛体を作成する
			@param builder 剛体のビルダー
			@return unique_ptr用弱参照クラス
			*/
			uwptr<RigidBody> createRigidBody(const RigidBodyBuilder& builder);

			/**
			@brief 剛体を削除する
			@param target 削除する剛体
			*/
			void removeRigidBody(const uwptr<RigidBody>& target);

			/**
			@brief 剛体リストを取得する
			@return 剛体リスト
			*/
			const std::list<uptr<RigidBody>>& getRigidBodies()const;

			/**
			@brief 剛体リストを取得する
			@param attribute 取得する剛体の属性
			@return 剛体リスト
			*/
			const std::list<uwptr<RigidBody>>& getRigidBodies(int attribute)const;

			/**
			@brief 衝突コールバックを追加する
			@param callback 追加するコールバック
			@return unique_ptr用弱参照クラス
			@note コールバックの所有権はWorldが持つ
			*/
			uwptr<CollisionCallback> addCollisionCallback(uptr<CollisionCallback>&& callback);

			/**
			@brief 衝突コールバックを削除する
			@param target 削除するコールバック
			*/
			void removeCollisionCallback(const uwptr<CollisionCallback>& target);

			/**
			@brief 衝突の検知及びコールバック関数の呼び出しを行う
			@note 特別なことがない限り毎フレーム呼ぶ
			*/
			void executeCollision();
		};
	}
}