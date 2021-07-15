#include <iostream>
#include <queue>

void setRequirements(int& elementsToAdd, int& elementsToRemove, int& elementToFind)
{
	std::cin >> elementsToAdd >> elementsToRemove >> elementToFind;
}

void setQueue(std::queue<int>& data, const int elementsToAdd, const int elementsToRemove)
{
	for (size_t i = 0; i < elementsToAdd; i++)
	{
		int element;
		std::cin >> element;

		data.push(element);
	}

	for (size_t i = 0; i < elementsToRemove; i++)
	{
		data.pop();
	}
}

bool findElementInQueue(std::queue<int>& data, const int elementToFind, int& minElement)
{
	minElement = INT32_MAX;

	while (!data.empty())
	{
		if (data.front() == elementToFind)
		{
			return true;
		}
		else
		{
			if (data.front() < minElement)
			{
				minElement = data.front();
			}
		}

		data.pop();
	}

	return false;
}

int main()
{
	int elementsToAdd = 0;
	int elementsToRemove = 0;
	int elementToFind = 0;
	int minElement = INT32_MAX;
	std::queue<int> data;

	setRequirements(elementsToAdd, elementsToRemove, elementToFind);
	setQueue(data, elementsToAdd, elementsToRemove);

	if (data.empty())
	{
		std::cout << 0;
	}
	else
	{
		if (findElementInQueue(data, elementToFind, minElement))
		{
			std::cout << "true";
		}
		else
		{
			std::cout << minElement;
		}
	}

	return 0;
}
