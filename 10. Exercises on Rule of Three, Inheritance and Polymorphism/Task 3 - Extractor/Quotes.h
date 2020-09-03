#ifndef QUOTES_H
#define QUOTES_H

#include "BufferedExtractor.h"

class Quotes : public BufferedExtractor
{
	int cnt = 0;
	bool getQuotes = false;
public:
	Quotes(std::istream& stream) :
		BufferedExtractor(stream) {}

	bool shouldBuffer(char symbol) override
	{
		while (this->getQuotes)
		{
			if (symbol == '"')
			{
				this->getQuotes = false;
				return false;
			}
			return true;
		}

		if (symbol == '"')
		{
			this->getQuotes = true;
		}
		return false;

		//if (symbol == '"')
		//{
		//	this->cnt++;
		//}
		//
		//if (this->cnt == 1)
		//{
		//	this->cnt++;
		//	return false;
		//}
		//else if (this->cnt == 2)
		//{
		//	return true;
		//}
		//else
		//{
		//	this->cnt = 0;
		//	return false;
		//}
	}
};

#endif // !QUOTES_H
