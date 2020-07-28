#pragma once

#include "Company.h"
#include <map>
#include <sstream>

std::string getProfitReport(Company* fromInclusive, Company* toInclusive, std::map<int, ProfitCalculator> &profitCalculatorsByCompany)
{
	std::ostringstream oss;

	while (fromInclusive != toInclusive)
	{
		oss << fromInclusive->getName() << " = " << profitCalculatorsByCompany[fromInclusive->getId()].calculateProfit(*fromInclusive) << "\n";

		fromInclusive++;
	}
	oss << fromInclusive->getName() << " = " << profitCalculatorsByCompany[fromInclusive->getId()].calculateProfit(*fromInclusive) << "\n";

	return oss.str();
}