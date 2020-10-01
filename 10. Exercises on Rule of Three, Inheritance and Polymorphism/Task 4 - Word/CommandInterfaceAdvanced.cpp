#include "CommandInterfaceAdvanced.h"

CommandInterfaceAdvanced::CutTransform::CutTransform(std::shared_ptr<std::string> clipboard) : clipboard(clipboard) 
{
}

void CommandInterfaceAdvanced::CutTransform::invokeOn(std::string& text, int startIndex, int endIndex)
{
	*clipboard = text.substr(startIndex, endIndex - startIndex);
	text.erase(startIndex, endIndex - startIndex);
}

CommandInterfaceAdvanced::PasteTransform::PasteTransform(std::shared_ptr<std::string> clipboard) : clipboard(clipboard) 
{
}

void CommandInterfaceAdvanced::PasteTransform::invokeOn(std::string& text, int startIndex, int endIndex)
{
	text.replace(startIndex, endIndex - startIndex, *clipboard);
}

CommandInterfaceAdvanced::CommandInterfaceAdvanced(std::string& text) : CommandInterface(text)
{
}

std::vector<Command> CommandInterfaceAdvanced::initCommands()
{
	std::vector<Command> commands;

	commands = CommandInterface::initCommands();

	std::shared_ptr<std::string> clipboard = std::make_shared<std::string>();

	commands.push_back(Command("cut", std::make_shared<CutTransform>(clipboard)));
	commands.push_back(Command("paste", std::make_shared<PasteTransform>(clipboard)));

	return commands;
}
