#ifndef CHARS_HH
#define CHARS_HH

#include <tuple>
#include <ostream>

template <char ...Args>
class Chars
{
    // allow insertions into ostreams
    template <char ...Params>
    friend std::ostream& operator<<(std::ostream& out, 
                                    Chars<Params...> const &chars);
};

template <char ...Args>
inline std::ostream &operator<<(std::ostream &out, Chars<Args...> const &chars)
{
    // Use unary left fold to insert each character into the stream
    return (out << ... << Args);
}


#endif