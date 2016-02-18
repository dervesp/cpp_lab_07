#include "stdafx.h"
#include <vector>
#include <string>

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

typedef const char * ConstCharArray;
template <>
bool FindMax<ConstCharArray>(std::vector<ConstCharArray> const & arr, ConstCharArray & maxValue)
{
	if (!arr.empty())
	{
		maxValue = arr[0];
		for (auto & arrItem : arr)
		{
			maxValue = (strcmp(arrItem, maxValue) > 0) ? arrItem : maxValue;
		}
		return true;
	}
	return false;
}