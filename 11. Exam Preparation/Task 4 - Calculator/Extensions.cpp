#include "Extensions.h"

std::shared_ptr<InputInterpreter> buildInterpreter(CalculationEngine& engine)
{
	return std::make_shared<ExtendedInputInterpreter>(engine);
}