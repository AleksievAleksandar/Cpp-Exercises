#ifndef QUOTES_EXTRACTOR_H
#define QUOTES_EXTRACTOR_H

#include "BufferedExtractor.h"

class QuotesExtractor : public BufferedExtractor
{
private:
	bool findQuotes;
public:
	QuotesExtractor(std::istream& stream) : BufferedExtractor(stream), findQuotes(false) {}
	
protected:
	virtual bool shouldBuffer(char symbol) override
	{
		if (symbol == '"')
		{
			this->findQuotes = !this->findQuotes;
			return false;
		}
		
		while (symbol != '"' && this->findQuotes)
		{
			return true;
		}

		return this->findQuotes;
	}
};

#endif // !QUOTES_EXTRACTOR_H
