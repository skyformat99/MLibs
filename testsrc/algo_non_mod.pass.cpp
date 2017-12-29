/*==============================================================================
 Name        : algo_non_mod.pass.cpp
 Author      : Stephen MacKenzie
 Copyright   : Licensed under GPL version 2 (GPLv2)
==============================================================================*/
#include "precompile.hpp"
#include "test_support.h"
/// Testing that the allocator is calling delete exactly once, be sure to run
/// address-sanitizer, it catches both double delete and leaks, test3 uses this.
int called = 0;
struct S {
	int *x = nullptr;
	S() { x = new int[10]; }
	~S()
	{
		delete[] x;
		called = 1;
	}
};
/// Testing with std::pairs and strings
///
void anmp_test1()
{
	TC_BEGIN(__func__);
	vector<std::pair<int, std::string>> v1;
	v1.push_back(std::make_pair(1, "one"));
	v1.push_back(std::make_pair(2, "two"));
	v1.push_back(std::make_pair(3, "three"));
	auto it = std::find_if(
	    v1.begin(), v1.end(),
	    [](const std::pair<int, std::string> &i) { return i.first == 3; });

	int res = (*it).first;
	VERIFY(res == 3);
}
/// might be a redundant test...
///
void anmp_test2()
{
	TC_BEGIN(__func__);
	vector<int> v{0, 1, 2, 3, 4, 5};
	auto v2 = v;
	bool res = std::equal(v.begin(), v.end(), v.begin());
	VERIFY(res == true);
}
/// std::accumulate non-modifying
///
void anmp_test3()
{
	TC_BEGIN(__func__);
	vector<int> v = {1, 2, 3, 4};
	int res = std::accumulate(v.begin(), v.end(), 0);
	VERIFY(res == 10);
	PASSED(__func__, __LINE__);
}
/// uses user defined type that allocates, checking that dtor gets called.
///
void anmp_test4()
{
	TC_BEGIN(__func__);
	{
		vector<S> v;
		v.push_back(S());
		v.clear();
		VERIFY(called == 1);
	}
}
/// same as above, but new up some S*, iterator and delete, check for
/// double free running address-sanitizer.
void anmp_test5()
{
	TC_BEGIN(__func__);
	vector<S *> v;
	for (int i = 0; i < 5; i++)
		v.push_back(new S);

	for (int i = 0; i < 5; i++)
		delete v[i];

	called = 0;
	VERIFY(called =5);
}
///
int algo_non_mod_pass()
{
	anmp_test1();
	anmp_test2();
	anmp_test3();
	anmp_test4();
	return failed;
}
