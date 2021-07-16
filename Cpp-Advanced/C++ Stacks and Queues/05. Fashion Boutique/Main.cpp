#include <iostream>
#include <stack>
#include <sstream>
#include <string>

void extractInput(std::stack<int>& inventory, int& capacity)
{
	std::string allClothes;
	std::getline(std::cin, allClothes);
	std::istringstream iss(allClothes);
	
	std::cin >> capacity;
	
	int currentClothe = 0;
	while (iss >> currentClothe)
	{
		inventory.push(currentClothe);
	}
}

int runFashionBoutique()
{
	int capacity = 0;
	int totalUsedRacks = 1;
	int currentSum = 0;
	std::stack<int> inventory;

	extractInput(inventory, capacity);

	while (!inventory.empty())
	{
		currentSum += inventory.top();
		if (capacity - currentSum >= 0)
		{
			inventory.pop();
		}
		else
		{
			totalUsedRacks++;
			currentSum = inventory.top();
			inventory.pop();
		}
	}

	return totalUsedRacks;
}

int main()
{
	std::cout << runFashionBoutique();

	return 0;
}
