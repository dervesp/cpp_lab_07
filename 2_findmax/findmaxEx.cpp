#include "stdafx.h"
#include <vector>

template < typename T, typename Less>
bool FindMaxEx(std::vector<T> const & arr, T & maxValue, Less const & less)
{
	if (!arr.empty())
	{
		size_t maxValueIndex = 0;
		for (auto currentIndex = 0; currentIndex < arr.size(); ++currentIndex)
		{
			maxValueIndex = less(arr[maxValueIndex], arr[currentIndex]) ? currentIndex : maxValueIndex;
		}
		maxValue = arr[maxValueIndex];
		return true;
	}
	return false;
}