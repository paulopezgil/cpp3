#ifndef CHARS_HH
#define CHARS_HH

#include <tuple>
#include <ostream>

template <size_t Num, size_t Radix>
class Convert
{
    enum {  }


    // allow insertions into ostreams
    template <size_t Num2, size_t Radix2>
    friend std::ostream& operator<<
    (std::ostream& out, Convert<size_t Num2, size_t Radix2> const &chars);
};

template <char ...Args>
inline std::ostream& operator<<
(std::ostream& out, Convert<size_t Num2, size_t Radix2> const &chars)
{
    out << 
}


#endif