#ifndef EXTENDED_COMMAND_INTERFACE_H
#define EXTENDED_COMMAND_INTERFACE_H

#include "CommandInterface.h"
#include "TextTransform.h"

class ExtendedCommandInterface : public CommandInterface
{
private:
	class Cut : public TextTransform
	{
	public:
		virtual void invokeOn(std::string& text, int startIndex, int endIndex) override {
			std::string temp(text, startIndex, endIndex - startIndex);
			text.erase(startIndex, endIndex - startIndex);
			ExtendedCommandInterface::clipboard = temp;
		}
	};

	class Paste : public TextTransform
	{
	public:
		virtual void invokeOn(std::string& text, int startIndex, int endIndex) override {
			text.replace(startIndex, endIndex - startIndex, ExtendedCommandInterface::clipboard);
		}
	};

protected:
	static std::string clipboard;

public:
	ExtendedCommandInterface(std::string& text) :
		CommandInterface(text) {}

	~ExtendedCommandInterface() = default;

public:
	virtual std::vector<Command> initCommands() override
	{
		std::vector<Command> commands;
		commands = CommandInterface::initCommands();
		
		commands.push_back(Command("cut", std::make_shared<Cut>()));
		commands.push_back(Command("paste", std::make_shared<Paste>()));

		return commands;
	}
};

std::string ExtendedCommandInterface::clipboard;

#endif // !EXTENDED_COMMAND_INTERFACE_H
