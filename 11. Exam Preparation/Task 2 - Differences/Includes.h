#ifndef INCLUDES_H
#define INCLUDES_H

#include "City.h"
#include "CityDiff.h"

#include <vector>
#include <utility>
#include <iostream>
#include <istream>

std::istream& operator>>(std::istream& in, City& city);

CityDiff operator-(const City& a, const City& b);

#endif // !INCLUDES_H
