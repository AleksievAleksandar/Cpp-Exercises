#ifndef PRINT_UTILS_H
#define PRINT_UTILS_H

#include <iostream>

template <typename T>
void printVector(std::vector<T> &data)
{
	for (size_t i = 0; i < data.size(); i++)
	{
		std::cout << data[i] << " ";
	}
}


#endif // !PRINT_UTILS_H

