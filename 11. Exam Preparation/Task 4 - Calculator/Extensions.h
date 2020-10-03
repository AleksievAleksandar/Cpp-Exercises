#ifndef EXTENSIONS_H
#define EXTENSIONS_H

#include <memory>

#include "InputInterpreter.h"
#include "ExtendedInputInterpreter.h"

std::shared_ptr<InputInterpreter> buildInterpreter(CalculationEngine& engine);

#endif // !EXTENSIONS_H
