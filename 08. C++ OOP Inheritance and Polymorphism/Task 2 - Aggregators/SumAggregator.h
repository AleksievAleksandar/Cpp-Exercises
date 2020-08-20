#pragma once

#include "Aggregator.h"

class SumAggregator : public StreamAggregator
{
public:
	SumAggregator(std::istream& stream);
	void aggregate(int num) override;
};