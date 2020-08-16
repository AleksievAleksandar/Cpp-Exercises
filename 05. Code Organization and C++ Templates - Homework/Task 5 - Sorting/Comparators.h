#ifndef COMPARATOR_H
#define COMPARATOR_H

#include "Song.h"

template<typename T>
struct LessThan {
    bool operator()(const T& lhs, const T& rhs) const {
        return lhs < rhs;
    };
};

template<typename T, typename Comparator>
struct Reverse {
    bool operator()(const T& lhs, const T& rhs) const {
        Comparator comparator;
        return !comparator(lhs, rhs);
    }
};

#endif // !COMPARATOR_H
