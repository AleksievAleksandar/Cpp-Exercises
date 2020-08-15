#ifndef OPERATORS_H
#define OPERATORS_H

#include <ostream>
#include <vector>
#include <string>
#include <sstream>


std::vector<std::string>& operator << (std::vector<std::string> &target, std::string &line)
{
	target.push_back(line);

	return target;
}

std::ostream& operator << (std::ostream &os, std::vector<std::string> &target)
{
	for (size_t i = 0; i < target.size(); i++)
	{
		os << target[i] << "\n";
	}

	return os;
}

std::string operator + (std::string &target, int &number)
{
	target += std::to_string(number);

	return target;
}

std::string operator + (std::string& target, size_t number)
{
	target += std::to_string(number);

	return target;
}


#endif // !OPERATORS_H

