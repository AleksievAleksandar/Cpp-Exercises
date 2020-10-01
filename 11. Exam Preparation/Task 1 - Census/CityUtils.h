#ifndef CITY_UTILIS_H
#define CITY_UTILIS_H

#include "City.h"

#include <string>
#include <vector>
#include <map>

const City* initCity(const std::string& name, size_t& population);

std::map<size_t, const City*> groupByPopulation(const std::vector<const City*>& cities, size_t& totalPopulation);

#endif // !CITY_UTILIS_H
