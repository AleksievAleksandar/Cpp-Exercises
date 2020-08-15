#ifndef SUMOFVECTORS_H
#define SUMOFVECTORS_H

#include <vector>
#include <string>

std::vector<std::string> operator + (std::vector<std::string> &a, std::vector<std::string> &b)
{
	std::vector<std::string> concatenation;

	for (size_t i = 0; i < a.size(); i++)
	{
		std::string temp;
		temp += a[i];
		temp += " ";
		temp += b[i];
		concatenation.push_back(temp);
	}
	return concatenation;
}

#endif // !SUMOFVECTORS_H