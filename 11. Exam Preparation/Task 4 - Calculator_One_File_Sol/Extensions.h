#ifndef EXTENSIONS_H
#define EXTENSIONS_H

#include <sstream>
#include <memory>
#include <stack>

#include "InputInterpreter.h"


class DevisionOperation : public Operation
{
	std::vector<int> operands;
	int result;
public:
	void addOperand(int operand)
	{
		this->operands.push_back(operand);

		if (this->isCompleted()) {
			this->result = this->operands[0] / this->operands[1];
		}
	}

	bool isCompleted()
	{
		return this->operands.size() == 2;
	}

	int getResult()
	{
		return this->result;
	}
};

class MemorySaveOperation : public Operation
{
	std::shared_ptr<std::stack<int> > result;
	bool complete = false;
public:
	MemorySaveOperation(std::shared_ptr<std::stack<int> > result) : result(result) {}

	void addOperand(int operand) override
	{
		this->result->emplace(operand);
		this->complete = true;
	}
	int getResult() override
	{
		return this->result->top();
	}
	bool isCompleted() override
	{
		return this->complete;
	}
};

class MemoryRecallOperation : public Operation
{
	std::shared_ptr<std::stack<int> > result;

public:
	MemoryRecallOperation(std::shared_ptr<std::stack<int> > result) : result(result) {}

	void addOperand(int operand) override
	{

	}

	int getResult() override
	{
		int getCurrentResult = this->result->top();
		this->result->pop();
		return getCurrentResult;
	}

	bool isCompleted() override
	{
		return true;
	}
};

class ExtendedInputInterpreter : public InputInterpreter
{
	std::shared_ptr<std::stack<int> > buffer;
public:
	ExtendedInputInterpreter(CalculationEngine& engine) : InputInterpreter(engine)
	{
		this->buffer = std::make_shared<std::stack<int> >();
	}

	std::shared_ptr<Operation> getOperation(std::string operation) override
	{
		std::shared_ptr<Operation> current = nullptr;
		if (operation == "*")
		{
			current = std::make_shared<MultiplicationOperation>();
			return current;
		}
		else if (operation == "/")
		{
			current = std::make_shared<DevisionOperation>();
			return current;
		}
		else if (operation == "ms")
		{
			current = std::make_shared<MemorySaveOperation>(buffer);
			return current;
		}
		else if (operation == "mr")
		{
			current = std::make_shared<MemoryRecallOperation>(buffer);
			return current;
		}

		return current;
	}
};

std::shared_ptr<InputInterpreter> buildInterpreter(CalculationEngine& engine)
{
	return std::make_shared<ExtendedInputInterpreter>(engine);
}

#endif // !EXTENSIONS_H

