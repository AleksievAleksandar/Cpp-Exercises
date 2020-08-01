#pragma once

#include "Company.h"
#include <vector>
#include <string>

Company* makeCompany(std::vector<std::string>& properties)
{
	size_t cnt = 0;
	int id = std::stoi(properties[cnt++]);
	std::string name = properties[cnt++];

	std::vector<std::pair<char, char> > employees{};

	while (cnt < properties.size())
	{
		employees.push_back({ properties[cnt][0], properties[cnt][1] });
		cnt++;
	}

	return new Company(id, name, employees);
}