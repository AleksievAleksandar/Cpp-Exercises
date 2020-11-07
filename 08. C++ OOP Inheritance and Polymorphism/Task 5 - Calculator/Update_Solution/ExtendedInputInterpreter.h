#ifndef EXTENDED_INPUT_INTERPRETER_H
#define EXTENDED_INPUT_INTERPRETER_H

#include "InputInterpreter.h"
#include "CalculationEngine.h"
#include "Operation.h"
#include "MultiplicationOperation.h"
#include "DevisionOperation.h"
#include "MemorySaveOperation.h"
#include "MemoryRecallOperation.h"

#include <string>
#include <memory>
#include <stack>

class ExtendedInputInterpreter : public InputInterpreter
{
	std::stack<int> clipboard;
public:
	ExtendedInputInterpreter(CalculationEngine& engine) :
		InputInterpreter(engine) {}

public:
	virtual std::shared_ptr<Operation> getOperation(std::string operation) override
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
			return std::make_shared<MemorySaveOperation>(clipboard);
		}
		else if (operation == "mr")
		{
			return std::make_shared<MemoryRecallOperation>(clipboard);
		}
		return nullptr;
	}
};


#endif // !EXTENDED_INPUT_INTERPRETER_H
