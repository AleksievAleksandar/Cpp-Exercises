#ifndef MAKE_COMPANY_H
#define MAKE_COMPANY_H

#include "Company.h"

#include <vector>
#include <memory>
#include <string>

std::shared_ptr<Company> makeCompany(const std::vector<std::string>& properties)
{
	int id = std::stoi(properties[0]);
	std::string name = properties[1];
	std::vector<std::pair<char, char> > employees;

	for (size_t i = 2; i < properties.size(); i++)
	{
		char first = properties[i][0];
		char last = properties[i][1];
		
		employees.emplace_back(first, last);
	}

	return std::make_shared<Company>(id, name, employees);
}

#endif // !MAKE_COMPANY_H
