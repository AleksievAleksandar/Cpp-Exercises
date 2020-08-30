#ifndef BYTE_CONTAINER_H
#define BYTE_CONTAINER_H

#include <sstream>

class ByteContainer
{
protected:
	std::string bytes;
public:
	ByteContainer() = default;
	virtual ~ByteContainer() = default;
	virtual std::string getBytes() const = 0;
};


/*
class ByteContainer {
private:
	const std::string bytes;

protected:
	explicit ByteContainer(std::string bytes) : bytes(std::move(bytes)) { }

	size_t getSize() const {
		return this->bytes.length();
	}

public:
	virtual ~ByteContainer() = default;

	const std::string& getBytes() const {
		return this->bytes;
	}
};
*/

#endif // !BYTE_CONTAINER_H