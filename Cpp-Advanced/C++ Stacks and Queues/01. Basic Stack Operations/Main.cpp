#include <iostream>
#include <stack>
#include <sstream>
#include <string>

int main()
{
	std::string requirements;
	std::getline(std::cin, requirements);

	std::istringstream oss(requirements);

	int elementsToPush = 0;
	int elementsToPop = 0;
	int x = 0;

	std::stack<int> dataColection;

	oss >> elementsToPush >> elementsToPop >> x;

	oss.clear();

	std::string data;
	std::getline(std::cin, data);
	
	oss.str(data);

	for (size_t i = 0; i < elementsToPush; i++)
	{
		int element;
		oss >> element;
		dataColection.push(element);
	}

	for (size_t i = 0; i < elementsToPop; i++)
	{
		dataColection.pop();
	}

	if (dataColection.empty())
	{
		std::cout << 0;
	}
	else
	{
		int minElem = INT32_MAX;
		bool findElement = false;

		while (!dataColection.empty())
		{
			if (x == dataColection.top())
			{
				std::cout << "true";
				findElement = true;
				break;
			}

			if (minElem > dataColection.top())
			{
				minElem = dataColection.top();
			}

			dataColection.pop();
		}
		if (!findElement)
		{
			std::cout << minElem;
		}
	}

	return 0;
}
