#include "stdafx.h"
#include <vector>

template < typename T, typename Less>
bool FindMaxEx(std::vector<T> const & arr, T & maxValue, Less const & less)
{
	if (!arr.empty())
	{
		maxValue = arr[0];
		for (auto & arrItem : arr)
		{
			maxValue = (less(maxValue, arrItem)) ? arrItem : maxValue;
		}
		return true;
	}
	return false;
}