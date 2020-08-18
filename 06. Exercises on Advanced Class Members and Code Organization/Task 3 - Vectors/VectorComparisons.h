#ifndef VECTOR_COMPARISONS_H
#define VECTOR_COMPARISONS_H

#include "Vector.h"

struct VectorLengthComparer {
    bool operator()(const Vector& first, const Vector& second) const {
        return first.getLength() < second.getLength();
    };
};

template<typename T, typename Comparator>
struct ReverseComparer {
    bool operator()(const T& first, const T& second) const {
        Comparator comparator;
        return !comparator(first, second);
    }
};

#endif // !VECTOR_COMPARISONS_H
