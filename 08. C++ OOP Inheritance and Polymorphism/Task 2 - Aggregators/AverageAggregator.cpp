#include "AverageAggregator.h"

AverageAggregator::AverageAggregator(std::istream& stream):
	StreamAggregator(stream), cnt(0), tempResult(0)
{
	this->aggregationResult = 0;
}

void AverageAggregator::aggregate(int num)
{
	cnt++;
	this->tempResult += num;
	this->aggregationResult = (tempResult / cnt);

	//StreamAggregator::aggregate(num);
	//this->tempResult += num;
	//this->aggregationResult = this->tempResult / StreamAggregator::getNumAggregated();
}
