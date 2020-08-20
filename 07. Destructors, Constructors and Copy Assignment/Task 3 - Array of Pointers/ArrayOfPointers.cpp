#include "ArrayOfPointers.h"

ArrayOfPointers::~ArrayOfPointers()
{
	for (size_t i = 0; i < this->companies.size(); i++)
	{
		delete companies[i];
	}
}

void ArrayOfPointers::add(Company* company)
{
	this->companies.push_back(company);
}

size_t ArrayOfPointers::getSize()
{
	return this->companies.size();
}

Company* ArrayOfPointers::get(size_t index)
{
	return this->companies[index];
}
