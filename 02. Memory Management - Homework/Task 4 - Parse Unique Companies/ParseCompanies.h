#pragma once

#include "Company.h"
#include <sstream>
#include <set>
#include <vector>
#include <algorithm>

Company* parseUniqueCompanies(const std::string& input, int& numCompanies, std::string(*func)(const Company& c))
{
	numCompanies = 0;

	std::vector<Company> companies;
	std::set<std::string> ids;

	std::istringstream iss(input);

	int id;
	std::string name;
	while (iss >> id >> name)
	{
		Company temp(id, name);
		if (!ids.count(func(temp)))
		{
			companies.push_back(temp);
			ids.insert(func(temp));
			numCompanies++;
		}
	}

	Company* compArray = new Company[numCompanies];
	for (size_t i = 0; i < numCompanies; i++)
	{
		compArray[i] = companies[i];
	}


	//std::vector<Company*> companies;
	//std::set<std::string> ids;
	//
	//std::istringstream iss(input);
	//
	//int id;
	//std::string name;
	//while (iss >> id >> name)
	//{
	//	Company temp(id, name);
	//	if (!ids.count(func(temp)))
	//	{
	//		companies.push_back(new Company(id, name));
	//		ids.insert(func(temp));
	//		numCompanies++;
	//	}
	//}
	//companies.push_back(nullptr);
	////std::set<Company*>::iterator itr;
	////itr = companies.begin();
	//return companies[0];

	return compArray;
}