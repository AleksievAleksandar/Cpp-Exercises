#ifndef FIND_H
#define FIND_H

#include "Company.h"

Company* find(std::vector<Company*> companies, int searchId)
{
	for (auto &i : companies)
	{
		if (i->getId() == searchId)
		{
			return i;
		}
	}
	return nullptr;
}

#endif // !FIND_H

