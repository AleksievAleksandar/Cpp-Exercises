#pragma once

#include <sstream>
#include <vector>

template <typename T>
class TypedStream
{
public:
	TypedStream(std::string input);
	virtual TypedStream<T>& operator>>(T& target);
	std::vector<T> readToEnd();

protected:
	std::istringstream stream;
};

template<typename T>
 TypedStream<T>::TypedStream(std::string input):
	stream(input)
{
}

template<typename T>
 TypedStream<T>& TypedStream<T>::operator>>(T& target)
{
	return *this;
}

template<typename T>
 std::vector<T> TypedStream<T>::readToEnd() 
{
	 std::vector<T> items;
	 T item;
	 this->operator>>(item);
	 while (this->stream) {
		 items.push_back(item);
		 this->operator>>(item);
	 }

	 return items;
}

