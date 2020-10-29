#ifndef INITIALIZATION_H
#define INITIALIZATION_H

#include "CommandInterface.h"
#include "ExtendedCommandInterface.h"

#include <string>
#include <memory>

std::shared_ptr<CommandInterface> buildCommandInterface(std::string& text)
{
	std::shared_ptr<ExtendedCommandInterface> interface = std::make_shared<ExtendedCommandInterface>(text);
	interface->init();
	return interface;
}

#endif // !INITIALIZATION_H
