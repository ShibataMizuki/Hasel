#pragma once

#include"../Hasel/HaselAlias.h"
#include<memory>

namespace hasel
{
	namespace algo
	{
		/**
		@brief アルゴリズム系補助クラス
		*/
		class AlgorithmHelper
		{
		public:
			/**
			@brief sptrを複製する
			@param original 複製元のsptr
			*/
			template<class Type>
			static sptr<Type> cloneShared(const sptr<Type>& original)
			{
				return move(make_shared<Type>(*original.get()));
			}
		};
	}
}