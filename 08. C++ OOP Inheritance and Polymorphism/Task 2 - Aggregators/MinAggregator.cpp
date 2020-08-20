#include "MinAggregator.h"

MinAggregator::MinAggregator(std::istream& stream):
	StreamAggregator(stream), getFirst(false)
{
}

void MinAggregator::aggregate(int num)
{
	if (!this->getFirst)
	{
		this->aggregationResult = num;
		this->getFirst = true;
	}
	else
	{
		if (this->aggregationResult > num)
		{
			this->aggregationResult = num;
		}
	}
}
