#ifndef TRY_PARSE_H
#define TRY_PARSE_H

#include <string>
#include <sstream>

bool tryParse(const std::string& aString, int& a)
{
	std::istringstream iss(aString);

	return (iss >> a) ? true : false;
}

#endif // !TRY_PARSE_H
