#ifndef COMMAND_INTERFACE_ADVANCED_H
#define COMMAND_INTERFACE_ADVANCED_H

#include "CommandInterface.h"
#include "TextTransform.h"

#include <string>
#include <vector>
#include <memory>

//extern std::string clipboard;

class CommandInterfaceAdvanced : public CommandInterface
{
private:
	class CutTransform : public TextTransform
	{
	private:
		std::shared_ptr<std::string> clipboard;

	public:
		CutTransform(std::shared_ptr<std::string> clipboard);
		void invokeOn(std::string& text, int startIndex, int endIndex) override;
	};

	class PasteTransform : public TextTransform
	{
	private:
		std::shared_ptr<std::string> clipboard;

	public:
		PasteTransform(std::shared_ptr<std::string> clipboard);
		void invokeOn(std::string& text, int startIndex, int endIndex) override;
	};


public:
	CommandInterfaceAdvanced(std::string& text);

protected:
	std::vector<Command> initCommands() override;
};

#endif //COMMAND_INTERFACE_ADVANCED_H
