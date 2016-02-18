#include "stdafx.h"
#include "../findmaxEx.cpp"
#include <vector>
#include <string>

struct Athlete
{
	std::string name;
	double height;
	double weight;
};

Athlete Ivan = { "Ivan Patrikeev", 175.5, 68.4 };
Athlete Sergey = { "Ivan Patrikeev", 190.8, 68.4 };
Athlete Boris = { "Ivan Patrikeev", 175.5, 90.21 };

std::vector<Athlete> emptyAthleteVector;
std::vector<Athlete> athleteVector = { Ivan, Sergey, Boris };

bool LessWeight(Athlete const & athlete1, Athlete const & athlete2)
{
	return (athlete1.weight < athlete2.weight);
}

bool LessHeight(Athlete const & athlete1, Athlete const & athlete2)
{
	return (athlete1.height < athlete2.height);
}

void checkAthleteEqual(Athlete const & athlete1, Athlete const & athlete2)
{
	bool isEqual = (athlete1.name == athlete2.name) && (athlete1.height == athlete2.height) && (athlete1.weight == athlete2.weight);
	BOOST_CHECK(isEqual);
}


BOOST_AUTO_TEST_SUITE(findmaxEx_function_)
	BOOST_AUTO_TEST_CASE(cannot_find_expected_item_in_empty_array)
	{
		{
			Athlete lessAthlete = Ivan;
			BOOST_CHECK(!FindMaxEx(emptyAthleteVector, lessAthlete, LessWeight));
			checkAthleteEqual(lessAthlete, Ivan);
		}
		{
			Athlete lessAthlete = Ivan;
			BOOST_CHECK(!FindMaxEx(emptyAthleteVector, lessAthlete, LessHeight));
			checkAthleteEqual(lessAthlete, Ivan);
		}
	}
	BOOST_AUTO_TEST_CASE(can_find_expected_item_in_nonempty_array)
	{
		{
			Athlete lessAthlete = Ivan;
			BOOST_CHECK(FindMaxEx(athleteVector, lessAthlete, LessWeight));
			checkAthleteEqual(lessAthlete, Boris);
		}
		{
			Athlete lessAthlete = Ivan;
			BOOST_CHECK(FindMaxEx(athleteVector, lessAthlete, LessHeight));
			checkAthleteEqual(lessAthlete, Sergey);
		}
	}
BOOST_AUTO_TEST_SUITE_END()