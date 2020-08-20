#include "SumAggregator.h"

SumAggregator::SumAggregator(std::istream& stream):
	StreamAggregator(stream)
{
	this->aggregationResult = 0;
}

void SumAggregator::aggregate(int num)
{
	this->aggregationResult += num;
}


