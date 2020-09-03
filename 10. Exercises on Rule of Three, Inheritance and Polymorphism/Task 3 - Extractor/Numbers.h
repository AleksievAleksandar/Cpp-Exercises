#ifndef NUMBERS_S
#define NUMBERS_H

#include "BufferedExtractor.h"

class Numbers : public BufferedExtractor
{
public:
	Numbers(std::istream& stream) :
		BufferedExtractor(stream) {}

	bool shouldBuffer(char symbol) override
	{
		return std::isdigit(symbol);
	}
};

#endif // !NUMBERS_S

