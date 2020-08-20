#pragma once

#include "Aggregator.h"

class MinAggregator : public StreamAggregator
{
public:
	MinAggregator(std::istream& stream);
	void aggregate(int num) override;
private:
	bool getFirst;
};