#include "ExtendedInputInterpreter.h"

#include <memory>

ExtendedInputInterpreter::ExtendedInputInterpreter(CalculationEngine& engine) :
	InputInterpreter(engine)
{
	this->buffer = std::make_shared<std::stack<int> >();
}

std::shared_ptr<Operation> ExtendedInputInterpreter::getOperation(std::string operation)
{
	if (operation == "*")
	{
		return std::make_shared<MultiplicationOperation>();
	}
	else if (operation == "/")
	{
		return std::make_shared<DevisionOperation>();
	}
	else if (operation == "ms")
	{
		return std::make_shared<MemorySaveOperation>(buffer);
	}
	else if (operation == "mr")
	{
		return std::make_shared<MemoryRecallOperation>(buffer);
	}

	return std::shared_ptr<Operation>(nullptr);
}
