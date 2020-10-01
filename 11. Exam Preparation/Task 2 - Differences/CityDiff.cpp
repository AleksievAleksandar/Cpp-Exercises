#include "CityDiff.h"

CityDiff::CityDiff(const City& a, const City& b) : a(a), b(b)
{
	this->population = (int)a.getPopulation() - (int)b.getPopulation();
}

std::ostream& operator<<(std::ostream& out, const CityDiff& cityDiff)
{
	if (cityDiff.a.getName() != cityDiff.b.getName())
	{
		out << cityDiff.a.getName() << " (" << cityDiff.a.getCensusYear() << ") vs. " << cityDiff.b.getName() << " (" << cityDiff.b.getCensusYear() << ")";
	}
	else
	{
		out << cityDiff.a.getName() << " (" << cityDiff.a.getCensusYear() << " vs. " << cityDiff.b.getCensusYear() << ")";
	}
	out << '\n';

	out << "population: ";
	if (cityDiff.population >= 0)
	{
		out << "+";
	}
	out << cityDiff.population << '\n';

	return out;
}
