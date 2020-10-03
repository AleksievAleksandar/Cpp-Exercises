#include "MemorySaveOperation.h"

MemorySaveOperation::MemorySaveOperation(std::shared_ptr<std::stack<int> > result) : result(result)
{
}

void MemorySaveOperation::addOperand(int operand)
{
	this->result->emplace(operand);
	this->complete = true;
}

int MemorySaveOperation::getResult()
{
	return this->result->top();
}

bool MemorySaveOperation::isCompleted()
{
	return this->complete;
}
