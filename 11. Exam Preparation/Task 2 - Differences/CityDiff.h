#ifndef CITY_DIFF_H
#define CITY_DIFF_H

#include "City.h"

#include <ostream>

class CityDiff
{
private:
	City a;
	City b;
	int population;

public:
	CityDiff(const City& a, const City& b);
	friend std::ostream& operator<<(std::ostream& out, const CityDiff& a);
};

std::ostream& operator<<(std::ostream& out, const CityDiff& a);

#endif // !CITY_DIFF_H
