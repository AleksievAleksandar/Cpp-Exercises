#pragma once

#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Car
{
public:
	Car(string brand, string name, int year);
	string GetBrand() const;
	string GetModel() const;
	int GetYear() const;

private:
	string brand;
	string name;
	int year;
};
