#ifndef FILE_H
#define FILE_H

#include "FileSystemObject.h"

#include <string>

class File : public FileSystemObject, public ByteContainer
{
	std::string content;
public:
	File(const std::string& fileName, const std::string& content) :
		FileSystemObject(fileName), content(content) {}
public:
	size_t getSize() const override
	{
		return this->content.size();
	}
	std::string getBytes() const override
	{
		return this->content;
	}
};

#endif // !FILE_H
