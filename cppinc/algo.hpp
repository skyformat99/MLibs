/*==============================================================================
 Name        : algo.hpp
 Author      : Stephen MacKenzie
 Copyright   : Licensed under GPL version 2 (GPLv2)
==============================================================================*/
#pragma once
#include "functors.hpp"
namespace stevemac
{
/// sort, default predicates provided for built-in types
template <typename Type, typename Pred = genless<Type>>
void sort(Type *first, Type *last, Pred pred = Pred())
{
	assert(first && last && last >= first);

	for (Type *key = (first + 1); key != last; key++)
		while (key > first && pred(*key, *(key - 1))) {
			Type tmp = *key;
			*key = *(key - 1);
			*(key - 1) = tmp;
			--key;
		}
}

/// visit, predicate does not return
template <typename InputIterator, typename Func>
void visit(InputIterator first, InputIterator last, Func func)
{

	while (first != last)
		func(*first++);
}
/// transform - modifies range with modifying operator
template <typename Iterator, typename Func>
void transform(Iterator input_first, Iterator input_last, Iterator output_first,
	       Func func)
{
	assert(input_first && input_last && input_last >= input_first);
	assert(output_first);
	while (input_first != input_last)
		*output_first++ = func(*input_first++);
}
/// for_each returns a functor object
template <typename InputIterator, typename Functor>
Functor for_each(InputIterator first, InputIterator last, Functor func)
{
	assert(first && last && last >= first);
	while (first != last)
		func(*first++);

	return func;
}
} // end namespace
