#include <iostream>
#include "Company.h"
#include <vector>
#include <sstream>
#include <algorithm>

void sortCompanies(std::vector<Company> &companies, const std::string &sortByNameOrById)
{
	if (sortByNameOrById == "id")
	{
		std::sort(companies.begin(), companies.end(), [](Company a, Company b) {return a.getId() < b.getId(); });
	}
	else
	{
		std::sort(companies.begin(), companies.end(), [](Company a, Company b) {return a.getName() < b.getName(); });
	}
}

std::vector<Company> getUserInfo()
{
	std::string line;
	std::vector<Company> companies;

	while (std::getline(std::cin, line) && line != "end")
	{
		std::istringstream iss(line);
		int id;
		std::string name;
		iss >> name >> id;

		companies.push_back(Company(id, name));

		line.clear();
	}

	return companies;
}

std::string printCompaniesInfo(std::vector<Company> companies)
{
	std::ostringstream oss;
	for (size_t i = 0; i < companies.size(); i++)
	{
		oss << companies[i].toString() << "\n";
	}
	return oss.str();
}

int main()
{
	std::vector<Company> companies;
	companies = getUserInfo();

	std::string sortingIdentification;
	std::cin >> sortingIdentification;

	sortCompanies(companies, sortingIdentification);

	std::cout << printCompaniesInfo(companies);

	return 0;
}
