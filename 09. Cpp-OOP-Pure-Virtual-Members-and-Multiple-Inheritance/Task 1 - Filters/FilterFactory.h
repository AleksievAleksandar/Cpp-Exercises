#pragma once

#include "Filter.h"
#include <sstream>

class DigitFilter : public Filter
{
public:
	DigitFilter() = default;
	bool shouldFilterOut(char symbol) const override;
};

class CapitalLettersFilter : public Filter
{
public:
	CapitalLettersFilter() = default;
	bool shouldFilterOut(char symbol) const override;
};

class NonCapitalLettersFilter : public Filter
{
public:
	NonCapitalLettersFilter() = default;
	bool shouldFilterOut(char symbol) const override;
};

class FilterFactory
{
public:
	FilterFactory() = default;
	Filter* buildFilter(std::string filterDefinition) const;
};