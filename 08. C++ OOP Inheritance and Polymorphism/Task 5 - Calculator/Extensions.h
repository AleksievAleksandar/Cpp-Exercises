#pragma once

#include <memory>
#include <vector>
#include <stack>
#include <string>

#include "InputInterpreter.h"
#include "CalculationEngine.h"
#include "Operation.h"

class DivisionOperation : public Operation
{
public:
	std::vector<int> operands;
	int result;
public:
	void addOperand(int operand) override 
	{
		this->operands.push_back(operand);

		if (this->isCompleted()) 
		{
			this->result = this->operands[0] / this->operands[1];
		}
	}

	bool isCompleted() override 
	{
		return this->operands.size() == 2;
	}

	int getResult() override 
	{
		return this->result;
	}
};

class MemoryStorage : public Operation
{
	std::stack<int> memory;
public:
	void addOperand(int operand) override 
	{
		this->memory.push(operand);
	}

	bool isCompleted() override 
	{
		return false;
	}

	int getResult() override 
	{
		int memoryTop = this->memory.top();
		this->memory.pop();
		return memoryTop;
	}
};

class MemoryRecall : public Operation
{
	std::shared_ptr<MemoryStorage> memory;
public:
	MemoryRecall(std::shared_ptr<MemoryStorage> memory) : memory(memory) {}

	void addOperand(int operand) 
	{
	}

	bool isCompleted() override 
	{
		return true;
	}

	int getResult() override 
	{
		return this->memory->getResult();
	}
};

class Extensions : public InputInterpreter
{
	std::shared_ptr<MemoryStorage> memory;
public:
	Extensions(CalculationEngine& engine) : InputInterpreter(engine) {}

	std::shared_ptr<Operation> getOperation(std::string operation) override {
		if (operation == "/")
		{
			return std::make_shared<DivisionOperation>();
		}
		else if (operation == "ms")
		{
			if (!memory)
			{
				memory = std::make_shared<MemoryStorage>();
			}

			return this->memory;
		}
		else if (operation == "mr")
		{
			return std::make_shared<MemoryRecall>(this->memory);
		}
		else
		{
			return InputInterpreter::getOperation(operation);
		}
	}
};

std::shared_ptr<InputInterpreter> buildInterpreter(CalculationEngine& engine) 
{
	return std::make_shared<Extensions>(engine);
}