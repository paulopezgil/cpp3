#ifndef RAW_CAPACITY_HH_
#define RAW_CAPACITY_HH_

#include <memory>

template <typename T>
T *rawCapacity(size_t cap)
{
    return static_cast<T *>(operator new(cap * sizeof(T)));
}

#endif