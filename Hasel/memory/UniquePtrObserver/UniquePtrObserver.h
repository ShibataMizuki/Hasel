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
			//! �Q�Ɛ��unique_ptr
			const std::unique_ptr<Type>* m_target;

		public:
			bool operator==(const UniquePtrObserver<Type>& rhs)
			{
				return this->lock().get() == rhs.lock().get();
			}

			/**
			@param unique �Q�Ƃ���unique_ptr
			*/
			UniquePtrObserver(const std::unique_ptr<Type>& unique)
			{
				m_target = &unique;
			}

			/**
			@brief �Q�Ƃ��Ă���unique_ptr������������Ă��邩�ǂ���
			@return bool true :����������Ă���
						 false:����������Ă��Ȃ��A�L���ł���
			*/
			bool expired()const
			{
				return !*m_target;
			}

			/**
			@brief �Q�Ƃ��Ă���unique_ptr���擾����
			*/
			const std::unique_ptr<Type>& lock()const
			{
				return *m_target;
			}
		};
	}
}