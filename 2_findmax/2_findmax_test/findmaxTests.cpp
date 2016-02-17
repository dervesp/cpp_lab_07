#include "stdafx.h"
#include "../findmax.cpp"
#include <vector>
#include <string>


BOOST_AUTO_TEST_SUITE(findmax_function_)
	BOOST_AUTO_TEST_CASE(cannot_find_maximum_in_empty_array)
	{
		{
			int intMax = 42;
			std::vector<int> emptyIntVector;
			BOOST_CHECK(!FindMax(emptyIntVector, intMax));
			BOOST_CHECK_EQUAL(intMax, 42);
		}
		{
			double doubleMax = 42.42;
			const std::vector<double> emptyDoubleVector;
			BOOST_CHECK(!FindMax(emptyDoubleVector, doubleMax));
			BOOST_CHECK_EQUAL(doubleMax, 42.42);
		}
		{
			std::string stringMax = "Deep Thought";
			const std::vector<std::string> emptyStringVector;
			BOOST_CHECK(!FindMax(emptyStringVector, stringMax));
			BOOST_CHECK_EQUAL(stringMax, "Deep Thought");
		}
	}
BOOST_AUTO_TEST_CASE(can_find_maximum_in_nonempty_array)
{
	{
		int intMax = 42;
		std::vector<int> intVector = {42, 12, 1000, 0, -1, 17};
		BOOST_CHECK(FindMax(intVector, intMax));
		BOOST_CHECK_EQUAL(intMax, 1000);
	}
	{
		double doubleMax = 42.42;
		const std::vector<double> doubleVector = {42.42, 12.12, 1000.1, 0, -1.1, 17.17};
		BOOST_CHECK(FindMax(doubleVector, doubleMax));
		BOOST_CHECK_EQUAL(doubleMax, 1000.1);
	}
	{
		std::string stringMax = "Deep Thought";
		const std::vector<std::string> stringVector = {"Deep", "Deep Thought", "Zaz", "aap", "   ollo"};
		BOOST_CHECK(FindMax(stringVector, stringMax));
		BOOST_CHECK_EQUAL(stringMax, "aap");
	}
}
BOOST_AUTO_TEST_SUITE_END()