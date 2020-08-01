#pragma once

#include <string>
#include <vector>

std::string minBy(std::vector<std::string> values, bool (*func)(const std::string& a, const std::string& b))
{
	std::string result = values[0];

	for (size_t i = 1; i < values.size(); i++)
	{
		if (func(values[i], result))
		{
			result = values[i];
		}
	}
	return result;
}
