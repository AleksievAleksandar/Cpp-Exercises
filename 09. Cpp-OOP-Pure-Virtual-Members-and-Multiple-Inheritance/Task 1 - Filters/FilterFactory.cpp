#include "FilterFactory.h"

bool DigitFilter::shouldFilterOut(char symbol) const
{
	if (std::isdigit(symbol))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CapitalLettersFilter::shouldFilterOut(char symbol) const
{
	if (std::isupper(symbol))
	{
		return true;
	}
	return false;
}

bool NonCapitalLettersFilter::shouldFilterOut(char symbol) const
{
	if (std::islower(symbol))
	{
		return true;
	}
	return false;
}

Filter* FilterFactory::buildFilter(std::string filterDefinition) const
{
	if (filterDefinition == "A-Z")
	{
		return new CapitalLettersFilter();
	}
	else if (filterDefinition == "a-z")
	{
		return new NonCapitalLettersFilter();
	}
	else if (filterDefinition == "0-9")
	{
		return new DigitFilter();
	}
	return nullptr;
}