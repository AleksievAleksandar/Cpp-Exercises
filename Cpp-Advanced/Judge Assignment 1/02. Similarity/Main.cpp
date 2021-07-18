#include <iostream>
#include <string>
#include <sstream>
#include <vector>

bool meetPercentage(const size_t hits, const size_t lenght, int persentage)
{
	return (((hits / (double)lenght) * 100) >= persentage);
} 

bool equalFirstAlpha(const std::string& target, const std::string& data)
{
	return target[0] == data[0];
}

bool equalLenght(const std::string& target, const std::string& data)
{
	return target.size() == data.size();
}

std::vector<std::string> extractWords(std::string& text)
{
	std::vector<std::string> words;
	std::string word;
	for (size_t i = 0; i < text.size(); i++)
	{
		if (isalpha(text[i]))
		{
			word += text[i];
			if (i == text.size() - 1)
			{
				words.push_back(word);
			}
		}
		else
		{
			words.push_back(word);
			word.clear();
		}
	}

	if (words.empty())
	{
		words.push_back(word);
	}

	return words;
}

size_t getHits(const std::string& target, const std::string& data)
{
	size_t hits = 0;
	for (size_t i = 0; i < target.size(); i++)
	{
		if (target[i] == data[i])
		{
			hits++;
		}
	}
	return hits;
}

size_t similarWords(std::string& text, std::istream& input)
{
	std::vector<std::string> words = extractWords(text);

	std::string target;
	int percentage;

	input >> target >> percentage;

	size_t wordCnt = 0; 
	
	for (size_t i = 0; i < words.size(); i++)
	{
		size_t hits = 0;
		if (equalFirstAlpha(target, words[i]) && equalLenght(target, words[i]))
		{
			hits = getHits(target, words[i]);

			if (meetPercentage(hits, target.size(), percentage))
			{
				wordCnt++;
			}
		}
	}

	return wordCnt;
}

int main()
{
	std::string text;
	std::getline(std::cin, text);
	
	std::cout << similarWords(text, std::cin);

	return 0;
}
