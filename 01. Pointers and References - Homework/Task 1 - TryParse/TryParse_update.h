#ifndef TRY_PARSE_H
#define TRY_PARSE_H

#include <string>
#include <sstream>

bool tryParse(const std::string& aString, int& a)
{
	std::istringstream iss(aString);
	if (iss >> a)
	{
		return true;
	}
	else
	{
		return false;
	}
}

#endif // !TRY_PARSE_H
