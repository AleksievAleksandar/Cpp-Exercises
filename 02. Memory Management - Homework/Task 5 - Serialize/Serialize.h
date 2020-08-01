#pragma once

#include "Company.h"
#include <sstream>
#include <vector>

byte* serializeToMemory(std::string input, size_t& bytesWritten)
{
	std::istringstream iss(input);
	std::vector<Company> companies;
	std::vector<std::string> stringResult;

	bytesWritten = 0;

	Company temp;
	while (iss >> temp)
	{
		companies.push_back(temp);
	}

	stringResult.push_back(std::to_string(companies.size()));
	bytesWritten++;

	for (size_t i = 0; i < companies.size(); i++)
	{
		stringResult.push_back(std::to_string(companies[i].getId()));
		bytesWritten++;

		stringResult.push_back(companies[i].getName());
		bytesWritten += companies[i].getName().size();

		stringResult.push_back("0");
		bytesWritten++;

		if (!companies[i].getEmployees().empty())
		{
			std::vector<std::pair<char, char>> employees = companies[i].getEmployees();

			stringResult.push_back(std::to_string(employees.size()));
			bytesWritten++;
			for (size_t a = 0; a < employees.size(); a++)
			{
				std::string firstName;
				firstName.push_back(employees[a].first);

				std::string secondName;
				secondName.push_back(employees[a].second);

				stringResult.push_back(firstName);
				stringResult.push_back(secondName);
				bytesWritten += 2;
			}
		}
		else
		{
			stringResult.push_back("0");
			bytesWritten++;
		}
	}

	byte* serial = new byte[bytesWritten];
	size_t cnt = 0;
	for (size_t i = 0; i < stringResult.size(); i++)
	{
		if (cnt < bytesWritten)
		{
			std::istringstream iss(stringResult[i]);
			int digit;
			if (iss >> digit)
			{
				serial[cnt] = digit;
				cnt++;
			}
			else
			{
				for (size_t a = 0; a < stringResult[i].size(); a++)
				{
					serial[cnt] = stringResult[i][a];
					cnt++;
				}
			}
		}
	}

	return serial;
}



/*std::vector<byte> serializeToBytes(const Company& company) {
	std::vector<byte> companyBytes;

	companyBytes.push_back(company.getId());

	for (char c : company.getName()) {
		companyBytes.push_back((byte)c);
	}
	companyBytes.push_back('\0');

	auto employees = company.getEmployees();
	companyBytes.push_back(employees.size());

	for (auto e : employees) {
		companyBytes.push_back((byte)e.first);
		companyBytes.push_back((byte)e.second);
	}

	return companyBytes;
}

byte* serializeToMemory(std::string companiesString, size_t& bytesWritten) {
	std::istringstream companiesIn(companiesString);

	std::vector<Company> companies;

	Company company;
	while (companiesIn >> company) {
		companies.push_back(company);
	}

	std::vector<byte> bytes;

	bytes.push_back(companies.size());

	for (Company c : companies) {
		auto companyBytes = serializeToBytes(c);
		bytes.insert(bytes.end(), companyBytes.begin(), companyBytes.end());
	}

	bytesWritten = bytes.size();
	byte* memory = new byte[bytes.size()];
	for (int i = 0; i < bytes.size(); i++) {
		memory[i] = bytes[i];
	}

	return memory;
}*/