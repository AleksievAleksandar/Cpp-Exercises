#include "Includes.h"

std::istream& operator>>(std::istream& in, City& city)
{
	unsigned int censusYear;
	std::string name;
	size_t population;

	in >> name >> population >> censusYear;
	City temp(censusYear, name, population);

	city = temp;

	return in;
}

CityDiff operator-(const City& a, const City& b)
{
	CityDiff newCity(a, b);
	return newCity;
}