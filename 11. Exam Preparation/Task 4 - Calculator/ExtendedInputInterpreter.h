#ifndef EXTENDED_INPUT_INTERPRETER_H
#define EXTENDED_INPUT_INTERPRETER_H

#include "Operation.h"
#include "InputInterpreter.h"
#include "CalculationEngine.h"
#include "DevisionOperation.h"
#include "MemorySaveOperation.h"
#include "MemoryRecallOperation.h"

#include <stack>

class ExtendedInputInterpreter : public InputInterpreter
{
	std::shared_ptr<std::stack<int> > buffer;
public:
	ExtendedInputInterpreter(CalculationEngine& engine);
	std::shared_ptr<Operation> getOperation(std::string operation) override;
};

#endif // !EXTENDED_INPUT_INTERPRETER_H
