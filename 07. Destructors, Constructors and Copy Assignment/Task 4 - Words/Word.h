#pragma once

#include <sstream>
#include <map>

class Word
{
public:
	Word() = default;
	Word(std::string& input);
	std::string getWord() const;
	int getCount() const;
	bool operator < (const Word& other) const;

private:
	static std::map<std::string, int> words;
	std::string name;
};

