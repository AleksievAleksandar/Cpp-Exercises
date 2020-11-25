#ifndef BYTE_CONTAINER_H
#define BYTE_CONTAINER_H

#include <string>

struct ByteContainer
{
	virtual std::string getBytes() const = 0;
	~ByteContainer() = default;
};

#endif // !BYTE_CONTAINER_H
