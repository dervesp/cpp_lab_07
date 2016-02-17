#include "stdafx.h"
#include <vector>

template <typename T>
bool FindMax(std::vector<T> const & arr, T & maxValue)
{
	if (!arr.empty())
	{
		maxValue = arr[0];
		for (auto & arrItem : arr)
		{
			maxValue = (arrItem > maxValue) ? arrItem : maxValue;
		}
		return true;
	}
	return false;
}