#include <iostream>
#include <stack>
#include <set>
#include <sstream>

enum CommandType
{
	PUSH = 1,
	DELETE = 2,
	PRINT_MAX = 3,
	PRINT_MIN = 4,

	UNKNOWN = 255
};

void runQueries(std::stack<int>& data, int numQueries)
{
	std::set<int> minAndMaxElements;
	std::ostringstream oss;

	while (numQueries > 0)
	{
		int element = 0;
		int command;
		std::cin >> command;

		switch (static_cast<CommandType>(command))
		{
		case CommandType::PUSH:

			std::cin >> element;

			data.push(element);
			minAndMaxElements.insert(element);

			break;

		case CommandType::DELETE:

			if (!data.empty())
			{
				minAndMaxElements.erase(data.top());
				data.pop();
			}

			break;

		case CommandType::PRINT_MAX:

			if (!minAndMaxElements.empty())
			{
				oss << *(--minAndMaxElements.end()) << std::endl;
			}

			break;

		case CommandType::PRINT_MIN:

			if (!minAndMaxElements.empty())
			{
				oss << *(minAndMaxElements.begin()) << std::endl;
			}

			break;

		default:
			break;
		}

		numQueries--;
	}

	while (!data.empty())
	{
		oss << data.top() << ", ";
		data.pop();
	}

	std::string result;
	result = oss.str().substr(0, oss.str().size() - 2);

	std::cout << result;
}

int main()
{
	std::stack<int> data;

	int numQueries = 0;
	std::cin >> numQueries;

	runQueries(data, numQueries);

	return 0;
}
