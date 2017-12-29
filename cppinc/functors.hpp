/*==============================================================================
 Name        : functors.hpp
 Author      : Stephen MacKenzie
 Copyright   : Licensed under GPL version 2 (GPLv2)
==============================================================================*/
#pragma once

/// Default predicates for common types, numeric, const char*
template <typename T> struct genless {
	bool operator()(const T &v1, const T &v2) const { return v1 < v2; }
};
template <> struct genless<const char *> {
	bool operator()(const char *s1, const char *s2) const
	{
		assert(s1 && s2);
		return (strcmp(s1, s2) < 0);
	}
};

/// test type
typedef struct student {
	const char *name;
	double gpa;
} student;

/// predicate for testing type
template <> struct genless<student> {
	bool operator()(const student &s1, const student &s2) const
	{
		if (s1.gpa == s2.gpa)
			return (strcmp(s1.name, s2.name) < 0);

		return (s1.gpa > s2.gpa);
	}
};
