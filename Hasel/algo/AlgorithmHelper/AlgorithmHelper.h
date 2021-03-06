#pragma once

#include"../Hasel/HaselAlias.h"
#include<memory>

namespace hasel
{
	namespace algo
	{
		/**
		@brief ASYnâNX
		*/
		class AlgorithmHelper
		{
		public:
			/**
			@brief sptrð¡»·é
			@param original ¡»³Ìsptr
			*/
			template<class Type>
			static sptr<Type> cloneShared(const sptr<Type>& original)
			{
				return move(make_shared<Type>(*original.get()));
			}
		};
	}
}