#ifndef PARSER_H
#define PARSER_H

#include <sstream>
//#include <istream>

template <typename T>
class Parser
{
public:
	Parser(std::istream& stream, std::string& stopLine) :
		stream(stream), stopLine(stopLine)
	{}
	
	bool readNext(T& data)
	{
		std::string line;
		std::getline(this->stream, line);
		//std::cin >> line; //I can used this line if I choose not to initialize stream field in Ctor
		if (line != this->stopLine)
		{
			std::istringstream iss(line);
			iss >> data;
			return true;
		}
		else
		{
			return false;
		}
	}
public:
	std::istream& stream;
	std::string stopLine;
};

#endif // !PARSER_H

