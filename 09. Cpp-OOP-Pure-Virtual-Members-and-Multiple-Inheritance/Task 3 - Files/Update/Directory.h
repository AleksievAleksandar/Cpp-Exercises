#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "FileSystemObjectsContainer.h"
#include "FileSystemObject.h"

#include <string>
#include <vector>

class Directory : public FileSystemObjectsContainer, public FileSystemObject
{
	std::vector<std::shared_ptr<FileSystemObject> > objects;
public:
	Directory(const std::string& directory) :
		FileSystemObject(directory) {}

public:
	void add(const std::shared_ptr<FileSystemObject>& obj) override
	{
		this->objects.push_back(obj);
	}
	size_t getSize() const override
	{
		int size = 0;
		for (size_t i = 0; i < this->objects.size(); i++)
		{
			size += this->objects[i]->getSize();
		}
		return size;
	}
};

#endif // !DIRECTORY_H
