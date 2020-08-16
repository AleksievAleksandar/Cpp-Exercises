#ifndef SPLIT_H
#define SPLIT_H

#include <vector>
#include <sstream>

template<typename T>
std::vector<T> split(const std::string& line, const char& symbol)
{
	std::vector<T> splitedObjects;
	
	std::string temp;
	for (size_t i = 0; i < line.size(); i++)
	{		
		if (line[i] != symbol && i < line.size() - 1 )
		{		
			temp += line[i];
		}
		else
		{
			if (i == line.size() - 1)
			{
				temp += line[i];
			}
			std::istringstream iss(temp);
			T data;
			iss >> data;
			splitedObjects.push_back(data);
			temp.clear();
		}
	}

	//std::string parsed;
	//std::stringstream ss(line);
	//while (std::getline(ss, parsed, symbol)) {
	//	T element;
	//	std::istringstream is(parsed);
	//	is >> element;
	//	splitedObjects.push_back(element);
	//}
	//
	return splitedObjects;
}

#endif // !SPLIT_H

