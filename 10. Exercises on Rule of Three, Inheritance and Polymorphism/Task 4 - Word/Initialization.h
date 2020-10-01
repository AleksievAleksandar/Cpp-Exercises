#ifndef INITIALIZATION_H
#define INITIALIZATION_H

#include <sstream>

#include "CommandInterface.h"
#include "CommandInterfaceAdvanced.h"

std::shared_ptr<CommandInterface> buildCommandInterface(std::string& text);

#endif // !INITIALIZATION_H
