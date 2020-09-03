#ifndef EXTRACTORS_H
#define EXTRACTORS_H

#include <sstream>
#include "BufferedExtractor.h"
#include "Extractor.h"
#include "Digits.h"
#include "Numbers.h"
#include "Quotes.h"

std::shared_ptr<Extractor> getExtractor(const std::string& extractType, std::istream& lineIn)
{
	if (extractType == "digits")
	{
		return std::make_shared<Digits>(lineIn);
		//return std::shared_ptr<Digits>(new Digits(lineIn));
	}
	else if (extractType == "numbers")
	{
		return std::make_shared<Numbers>(lineIn);
	}
	else if (extractType == "quotes")
	{
		return std::make_shared<Quotes>(lineIn);
	}
	else
	{
		return nullptr;
	}
}

#endif // !EXTRACTOR_H