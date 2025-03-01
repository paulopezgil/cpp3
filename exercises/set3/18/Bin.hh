#ifndef BIN_HH
#define BIN_HH

#include <iosfwd>

template <size_t Nr>
struct Bin
{
    enum { value = (Nr & 1) + 10 * Bin<(Nr >> 1)>::value };
};

template <>
struct Bin<0>
{
    enum { value = 0 };
};

#endif