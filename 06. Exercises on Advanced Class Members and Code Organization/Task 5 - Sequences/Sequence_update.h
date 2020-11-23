#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <vector>

template<typename T>
class Iterator {
private:
	static const int END_ITERATOR_INDEX = -1;

	std::vector<T>& elements;
	int next;

	explicit Iterator(std::vector<T>& elements, int next) : 
		elements(elements), next(next) { }

public:
	static Iterator begin(std::vector<T>& elements) 
	{
		if (elements.size() == 0) 
		{
			return end(elements);
		}
		return Iterator(elements, 0);
	}

	static Iterator end(std::vector<T>& elements) 
	{
		return Iterator(elements, END_ITERATOR_INDEX);
	}

	bool operator!=(const Iterator& other) const 
	{
		return this->elements != other.elements || this->next != other.next;
	}

	Iterator& operator++() 
	{
		++this->next;
		if (this->next >= this->elements.size()) 
		{
			this->next = END_ITERATOR_INDEX;
		}
		return *this;
	}

	T& operator*() const 
	{
		return this->elements.at(this->next);
	}
};

template<typename T, typename Generator>
class Sequence
{
private:
	Generator generator;
	std::vector<T> elements;

public:
	void generateNext(int numToGenerate)
	{
		for (size_t i = 0; i < numToGenerate; i++)
		{
			elements.push_back(generator());
		}
	}

	Iterator<T> begin()
	{
		return Iterator<T>::begin(this->elements);
	}
	Iterator<T> end()
	{
		return Iterator<T>::end(this->elements);
	}

};

#endif // !SEQUENCE_H
