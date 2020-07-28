#pragma once

#include <vector>
#include "Company.h"

typedef unsigned char byte;

std::vector<Company> readCompaniesFromMemory(byte* memory, int numCompanies)
{
	std::vector<Company> company;
	size_t cnt = 0;

	for (size_t i = 0; i < numCompanies; i++)
	{
		int id = memory[cnt];
		cnt++;

		std::string name;

		while (memory[cnt] != 0)
		{
			name += memory[cnt];
			cnt++;
		}
		cnt++;

		std::vector<std::pair<char, char> > employees;
		int howManyEmployees = memory[cnt];
		cnt++;

		while (howManyEmployees != 0)
		{
			char firstName = memory[cnt];
			cnt++;
			char lastName = memory[cnt];
			cnt++;

			employees.push_back({firstName, lastName});

			howManyEmployees--;
		}

		company.push_back(Company(id, name, employees));
		if (memory[cnt] == '\0')
		{
			break;
		}
	}

	return company;
}