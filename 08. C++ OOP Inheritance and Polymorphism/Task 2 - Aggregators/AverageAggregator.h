#pragma once

#include "Aggregator.h"

class AverageAggregator : public StreamAggregator
{
public:
	AverageAggregator(std::istream& stream);
	void aggregate(int num) override;
private:
	int cnt;
	int tempResult;
};