#include "Car.h"


Car::Car(string brand, string name, int year):
	brand(brand), name(name), year(year)
{
}

string Car::GetBrand() const
{
	return this->brand;
}

string Car::GetModel() const
{
	return this->name;
}

int Car::GetYear() const
{
	return this->year;
}
