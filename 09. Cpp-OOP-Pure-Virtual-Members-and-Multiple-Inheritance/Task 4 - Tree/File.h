#ifndef FILES_H
#define FILES_H

#include "FileSystemObject.h"
#include "ByteContainer.h"
#include <sstream>
#include <cstdlib>

class File : public FileSystemObject, public ByteContainer
{
	//std::string bytes;
public:
	File() = default;
	File(std::string& fileName, std::string bytes):
		FileSystemObject(fileName)
	{
		this->bytes = bytes;
	}

	std::string getBytes() const override
	{
		return bytes;
	}

	size_t getSize() const override
	{
		return bytes.size();
	}
	
};

#endif // !FILES_H