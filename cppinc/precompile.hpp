/*==============================================================================
 Name        : precompile.h
 Author      : Stephen MacKenzie
 Copyright   : Licensed under GPL version 2 (GPLv2)
==============================================================================*/
#pragma once
#include <algorithm>
#include <cassert>
#include <cstdbool>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <exception>
#include <initializer_list>
#include <memory>
#include <numeric>
#include <limits>
#include <stdarg.h>
#include <string>
#include <type_traits>
#include <utility>
#include <queue>

// Macro and template to calculate array lengths
#ifndef _gridcountof
#define _gridcountof(x) sizeof(x) / sizeof(x[0][0])
#endif

typedef void* genptr;

#ifndef _countof
template <typename T, size_t N> constexpr size_t _countof(T (&)[N])
{
	return N;
}
#endif

/* TEST HARNESS*/
extern int passed;
extern int failed;
extern int tcs;
#define TC_BEGIN(func) \
	printf("--------------------TESTCASE BEGIN %s ---------------------\n", func); \
	tcs++;
#define VERIFY(x) \
	(x) ? passed++ : failed++; \
	assert(x)
#define PASSED(func, line) \
	printf("--------------------PASSED %s Line: %d --------------------\n", func, line); \
	passed++;
#define REPORT(msg) \
	printf("--%s TESTCASES: %d TESTS PASSED: %d TESTS FAILED: %d-------\n", msg, tcs, passed, failed);




