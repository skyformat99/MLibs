/*==============================================================================
 Name        : validate.h
 Author      : Stephen MacKenzie
 Copyright   : Licensed under GPL version 2 (GPLv2)
==============================================================================*/
#pragma once

void STEVEMAC_TRACE(const char *fmt, ...);

/// returns the size of a (statically available) raw array of T
template <typename T, size_t N> constexpr size_t array_size(T (&)[N])
{
	return N;
}

template <typename T> void dump(const vector<T> &v)
{

	printf("capacity: %d size: %d\n", v.capacity(), v.size());

}
template <typename T> void dump(vector<T> &v, const char *msg)
{
	printf("%s\n", msg);
	dump(v);
}
template <typename T>
bool validate_cap(const vector<T> &v, const typename vector<T>::size_type cap)
{

	if (v.capacity() != cap) {
		STEVEMAC_TRACE("expected cap: %d actual: %d\n", cap, v.capacity());
		return false;
	}
	return true;
}

/// Useful function to check the valid state of a vector after some operation.
/// If a vector can be reversed and sorted, its state can be assumed to be
/// reasonably stable (one would think :-) ).
template <typename T>
bool reverse_sort_compare(vector<T> &v, const vector<T> &compare)
{
	std::reverse(v.begin(), v.end());
	std::sort(v.begin(), v.end());
	return v == compare;
}

template <typename T> void ilpush(vector<T> &v, std::initializer_list<T> il)
{

	for (auto &i : il)
		v.push_back(i);
}

