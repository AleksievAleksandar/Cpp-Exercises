#include "Initialization.h"

//std::string clipboard = "";

std::shared_ptr<CommandInterface> buildCommandInterface(std::string& text)
{
	std::shared_ptr<CommandInterface> myInterface = std::make_shared<CommandInterfaceAdvanced>((text));
	myInterface->init();
	return myInterface;
}
