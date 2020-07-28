#pragma once

#include <sstream>

bool tryParse(std::string data, int& result)
{
	std::istringstream iss(data);
	int tempNumber;
	int isNumber = false;
	while (iss >> result)
	{
		isNumber = true;
	}

	return isNumber;
}