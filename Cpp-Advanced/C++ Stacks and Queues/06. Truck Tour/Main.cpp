#include <iostream>
#include <vector>
#include <utility>
#include <set>

std::vector<std::pair<int, int> > extractInput()
{
	int lines = 0;
	std::cin >> lines;

	std::vector<std::pair<int, int> > pumpCircle;

	for (size_t i = 0; i < lines; i++)
	{
		int capacityCurrPump = 0;
		int distanceToNextPump = 0;

		std::cin >> capacityCurrPump >> distanceToNextPump;

		pumpCircle.push_back({capacityCurrPump, distanceToNextPump});
	}

	return pumpCircle;
}

void runTour(std::vector<std::pair<int, int> >& pumpCircle)
{
	std::set<int> minInd;

	for (size_t i = 0; i < pumpCircle.size(); i++)
	{
		int fuel = pumpCircle[i].first - pumpCircle[i].second;

		if (0 < fuel)
		{
			size_t tempIndx = i + 1;

			if (tempIndx >= pumpCircle.size() - 1)
			{
				tempIndx = 0;
			}

			while (tempIndx != i)
			{
				fuel += pumpCircle[tempIndx].first - pumpCircle[tempIndx].second;
				tempIndx++;

				if (fuel < 0)
				{
					break;
				}
				if (tempIndx > pumpCircle.size() - 1)
				{
					tempIndx = 0;
				}
			}
			if (tempIndx == i && 0 < fuel)
			{
				minInd.insert(i);
			}
		}
	}

	std::cout << *(minInd.upper_bound(-1));
}

int main()
{
	std::vector<std::pair<int, int> > pumpCircle;
	pumpCircle = extractInput();

	runTour(pumpCircle);

	return 0;
}
