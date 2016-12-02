#pragma once

#include<memory>

namespace hasel
{
	namespace memory
	{
		/**
		@brief unique_ptr
		*/
		template<class Type>
		class UniquePtrObserver
		{
		private:
			//! 参照先のunique_ptr
			const std::unique_ptr<Type>* m_target;

		public:
			bool operator==(const UniquePtrObserver<Type>& rhs)
			{
				return this->lock().get() == rhs.lock().get();
			}

			/**
			@param unique 参照するunique_ptr
			*/
			UniquePtrObserver(const std::unique_ptr<Type>& unique)
			{
				m_target = &unique;
			}

			/**
			@brief 参照しているunique_ptrが無効化されているかどうか
			@return bool true :無効化されている
						 false:無効化されていない、有効である
			*/
			bool expired()const
			{
				return !*m_target;
			}

			/**
			@brief 参照しているunique_ptrを取得する
			*/
			const std::unique_ptr<Type>& lock()const
			{
				return *m_target;
			}
		};
	}
}