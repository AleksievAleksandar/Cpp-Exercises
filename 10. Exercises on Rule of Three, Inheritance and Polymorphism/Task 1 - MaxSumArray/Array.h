#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>

template<typename T>
class Array
{
	T* arr;
	size_t size;
public:
	Array(size_t size) :
		arr(new T[size]), size(size) {}

	Array(const Array<T>& other) :
		Array(other.size)
	{
		for (size_t i = 0; i < other.size; i++)
		{
			this->arr[i] = other.arr[i];
		}
	}

	~Array()
	{
		delete[] this->arr;
	}
public:
	size_t getSize() const
	{
		return this->size;
	}

	T& operator[](size_t element)
	{
		return this->arr[element];
	}

	Array<T>& operator=(const Array<T>& other)
	{
		if (this != &other)
		{
			this->size = other.size;
			delete[] this->arr;

			this->arr = new T[other.size];
			for (size_t i = 0; i < other.size; i++)
			{
				this->arr[i] = other.arr[i];
			}
		}
		return *this;
	}

	T* begin()
	{
		return this->arr;
	}
	T* end()
	{
		return this->arr + this->size;
	}
};

#endif // !ARRAY_H
