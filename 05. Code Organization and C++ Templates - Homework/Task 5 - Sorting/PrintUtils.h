#ifndef PRINT_UTILS_H
#define PRINT_UTILS_H

#include <iostream>

template<typename T>
void printContainer(typename T::iterator begin, typename T::iterator end) {
    while (begin != end) {
        std::cout << *begin << " ";
        ++begin;
    }
    std::cout << "\n";
}


#endif // !PRINT_UTILS_H

