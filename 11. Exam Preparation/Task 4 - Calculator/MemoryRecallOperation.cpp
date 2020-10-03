#include "MemoryRecallOperation.h"

MemoryRecallOperation::MemoryRecallOperation(std::shared_ptr<std::stack<int> > result) : result(result)
{
}

void MemoryRecallOperation::addOperand(int operand)
{
	
}

int MemoryRecallOperation::getResult()
{
	int getCurrentResult = this->result->top();
	this->result->pop();
	return getCurrentResult;
}

bool MemoryRecallOperation::isCompleted()
{
	return !(this->result->empty());
}
