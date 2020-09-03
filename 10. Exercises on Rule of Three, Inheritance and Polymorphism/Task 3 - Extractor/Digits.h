#ifndef DIGITS_H
#define DIGITS_H

#include "Extractor.h"

class Digits : public Extractor
{
public:
	Digits(std::istream& stream) :
		Extractor(stream) {}

	bool process(char symbol, std::string& output) override
	{
		if (std::isdigit(symbol))
		{
			output.clear();
			output += symbol;
			return true;
		}
		return false;
	}
};

#endif // !DIGITS_H

