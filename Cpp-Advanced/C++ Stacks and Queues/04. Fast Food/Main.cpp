#include <iostream>
#include <queue>
#include <sstream>
#include <string>

void startRestaurant()
{
	int totalFoodPerDay = 0;
	std::cin >> totalFoodPerDay;
	std::cin.clear();
	std::cin.ignore();

	std::string allOrders;
	std::getline(std::cin, allOrders);

	std::istringstream iss(allOrders);

	int currentOrder = 0;
	int biggestOrder = INT32_MIN;
	std::queue<int> ordersLeft;

	bool foodIsEnough = true;

	while (iss >> currentOrder)
	{
		if (biggestOrder < currentOrder)
		{
			biggestOrder = currentOrder;
		}

		if (totalFoodPerDay - currentOrder >= 0 && foodIsEnough)
		{
			totalFoodPerDay -= currentOrder;
		}
		else
		{
			ordersLeft.push(currentOrder);
			foodIsEnough = false;
		}
	}

	std::cout << biggestOrder << std::endl;

	if (foodIsEnough)
	{
		std::cout << "Orders complete";
	}
	else
	{
		std::cout << "Orders left: ";

		while (!ordersLeft.empty())
		{
			std::cout << ordersLeft.front() << " ";
			ordersLeft.pop();
		}
	}
}

int main()
{
	startRestaurant();
	return 0;
}
