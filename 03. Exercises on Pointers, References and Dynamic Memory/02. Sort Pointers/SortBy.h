#pragma once
#include "Company.h"
#include <algorithm>
#include <iostream>

void swapCompanies(Company*& first, Company*& second)
{
	Company* temp;
	temp = first;
	first = second;
	second = temp;
}

void sortBy(Company** companyPtrsBegin, Company** companyPtrsEnd, bool (*func)(const Company& a, const Company& b))
{

	//std::sort(companyPtrsBegin, companyPtrsEnd, [&](Company* const& a, Company* const& b) {
	//	return func(*a, *b);
	//	});

	Company** getFirstPtr = companyPtrsBegin;
	size_t sizeComp = 0;

	while (companyPtrsBegin < companyPtrsEnd)
	{
		sizeComp++;
		companyPtrsBegin++;
	}

	companyPtrsBegin = getFirstPtr;

	for (int i = 0; i < sizeComp; i++)
	{
		for (int a = 0; a < sizeComp - 1 - i; a++)
		{
			if (func(*companyPtrsBegin[a + 1], *companyPtrsBegin[a]))
			{
				swapCompanies(companyPtrsBegin[a + 1], companyPtrsBegin[a]);
			}
		}
	}
}