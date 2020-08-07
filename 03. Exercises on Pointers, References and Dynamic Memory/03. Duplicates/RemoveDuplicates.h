#pragma once
#include "Company.h"
#include <list>
#include <set>

void removeDuplicates(std::list<Company*>& companies)
{
	//companies.sort();   //does not work
    //companies.unique(); //does not work

	std::set<Company*> uniquePtr;
	std::set<std::string> uniqueNames;

	auto it = companies.begin();
	while (it != companies.end()) {
		//Company* company = *it;
		if (!uniquePtr.insert(*it).second) {
			it = companies.erase(it);
		}
		else if (!uniqueNames.insert((*it)->getName()).second) {
			//delete company;
			it = companies.erase(it);
		}
		else {
			++it;
		}
	}
}