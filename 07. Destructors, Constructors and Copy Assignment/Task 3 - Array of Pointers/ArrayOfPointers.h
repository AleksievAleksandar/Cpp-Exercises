#pragma once

#include <vector>
#include <sstream>
#include "Company.h"

class ArrayOfPointers
{
public:
	ArrayOfPointers() = default;
	~ArrayOfPointers();
	void add(Company* company);
	size_t getSize();
	Company* get(size_t index);

public:
	std::vector<Company*> companies;
};