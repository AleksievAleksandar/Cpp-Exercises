#ifndef EXTENSIONS_H
#define EXTENSIONS_H

#include "InputInterpreter.h"
#include "CalculationEngine.h"
#include "ExtendedInputInterpreter.h"

#include <memory>

std::shared_ptr<InputInterpreter> buildInterpreter(CalculationEngine& engine)
{
	return std::make_shared<ExtendedInputInterpreter>(engine);
}

#endif // !EXTENSIONS_H
