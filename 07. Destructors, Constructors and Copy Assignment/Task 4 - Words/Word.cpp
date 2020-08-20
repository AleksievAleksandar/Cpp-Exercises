#include "Word.h"

std::map<std::string, int> Word::words{};

Word::Word(std::string& input):
	name(input)
{
	words[input]++;
}

std::string Word::getWord() const
{
	words.erase(this->name);
	return this->name;
}

int Word::getCount() const
{
	std::map<std::string, int>::iterator itr;
	itr = words.find(this->name);
	return itr->second;
}

bool Word::operator<(const Word& other) const
{
	return this->name < other.name;
}

