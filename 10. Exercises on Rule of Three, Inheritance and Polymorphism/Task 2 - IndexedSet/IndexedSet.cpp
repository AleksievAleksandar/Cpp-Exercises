#include "IndexedSet.h"
#include <algorithm>

IndexedSet::IndexedSet():
	valuesSet{}, valuesArray(nullptr)
{
}

IndexedSet::IndexedSet(const IndexedSet& other):
	valuesSet(other.valuesSet), valuesArray(nullptr)
{
	if (other.valuesArray != nullptr)
	{
		this->valuesArray = new Value[other.valuesSet.size()];
		for (size_t i = 0; i < this->valuesSet.size(); i++)
		{
			this->valuesArray[i] = other.valuesArray[i];
		}
	}
}

void IndexedSet::add(const Value& v)
{
	this->valuesSet.insert(v);
	if (this->valuesArray != nullptr)
	{
		delete[] this->valuesArray;
		this->valuesArray = nullptr;
	}
}

size_t IndexedSet::size() const
{
	return this->valuesSet.size();
}

const Value& IndexedSet::operator[](size_t index)
{
	if (this->valuesArray == nullptr)
	{
		this->valuesArray = new Value[this->valuesSet.size()];
		size_t cnt = 0;

		for (auto i : this->valuesSet)
		{
			this->valuesArray[cnt++] = i;
		}
	}
	return this->valuesArray[index];
}

IndexedSet& IndexedSet::operator=(const IndexedSet& other)
{
	if (this != &other)
	{
		if (this->valuesArray != nullptr)
		{
			delete[] this->valuesArray;
			this->valuesArray = nullptr;
		}
		this->valuesSet = other.valuesSet;
	}
	return *this;
}

IndexedSet::~IndexedSet()
{
	if (this->valuesArray != nullptr)
	{
		delete[] this->valuesArray;
	}
}
