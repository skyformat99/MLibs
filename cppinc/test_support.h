/*==============================================================================
 Name        : test_support.h
 Author      : Stephen MacKenzie
 Copyright   : Licensed under GPL version 2 (GPLv2)
==============================================================================*/
///
/// \file test_support.h
/// \brief Provides code reuse for testing stevemac::vector. The template class:
/// Test is specialized on given scenarios and states such as copying a
/// default constructed stevemac::vector to another default constructed
/// stevemac::vector.
/// The tests can be used to test std::vector as well by defining
/// _STD_VECTOR_TEST in the libcxx/test/testit script.
//===----------------------------------------------------------------------===//
#pragma once
#include "vector.hpp"
using stevemac::vector;
#include "validate.h"


/// REVIEW used for spcializing the Test templates. It provides terseness
/// when writing Test instances.  Open to suggestions...
/// this enum describes the type of operation such as "copy assign"
const bool copy = false;
const bool move = true;
const bool empty = true;
const bool diff = false;

/// Primary template:
template <typename T, bool Move, bool EmptyState> struct Test {
};

/// Specialization: copy construct,both source and destination are empty.
template <typename T> struct Test<T, copy, empty> {

	bool execute(const vector<T> &x, const vector<T> &y)
	{

		if (!validate_cap(x, 0))
			return false;
		if (!validate_cap(y, 0))
			return false;

		return x == y;
	}
};
// copy, at copied from not empty
template <typename T> struct Test<T, copy, diff> {
	bool execute(vector<T> x, vector<T> y)
	{

		if (!reverse_sort_compare(x, x))
			return false;
		if (!reverse_sort_compare(y, y))
			return false;

		return x == y;
	}
};
// move both empty
template <typename T> struct Test<T, move, empty> {

	bool execute(const vector<T> &movedfrom, vector<T> &v)
	{

		if (!validate_cap(v, 0))
			return false;

		return reverse_sort_compare(v, v);
	}
};
//
// move moved from not empty
template <typename T> struct Test<T, move, diff> {

	bool execute(vector<T> &movedfrom, vector<T> &v,
		     const typename vector<T>::size_type cap)
	{

		if (!validate_cap(v, cap))
			return false;

		return reverse_sort_compare(v, v);
	}
};

template <typename T> struct Checked {
	bool execute(vector<T> &src, vector<T> &dest)
	{
		bool caught = false;
		try {
			std::copy(src.begin(), src.end(), dest.begin());
		} catch (std::out_of_range &e) {
			STEVEMAC_TRACE("out_of_range caught\n");
			caught = true;
		} catch (...) {
			STEVEMAC_TRACE("unexpected");
		}
		return caught;
	}
};
