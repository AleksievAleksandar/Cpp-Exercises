#ifndef ORDERED_INSERTER_H 
#define ORDERED_INSERTER_H

#include "Company.h"
#include <vector>
#include <algorithm>

class OrderedInserter
{
public:
	OrderedInserter(std::vector<const Company*>& companies):
		companies(companies)
	{

	}
	void insert(const Company* c)
	{
		this->companies.push_back(c);
		std::sort(this->companies.begin(), this->companies.end(), 
			[](const Company* a, const Company* b) {return a->getId() < b->getId(); });
	}

private:
	std::vector<const Company*> &companies;
};


#endif // !ORDERED_INSERTER_H
