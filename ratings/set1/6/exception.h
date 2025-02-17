// ES: 1
#ifndef INCLUDED_EXCEPTION_
#define INCLUDED_EXCEPTION_

#include <sstream>
#include <exception>

class Exception: public std::exception
{
    std::string d_what;

    template <typename Type>
    friend Exception &&operator<<(Exception &&in, Type arg);

    public:
        Exception() = default;

        char const *what() const noexcept(true) override;   
};

#include "exception.i"  // operator<< definition

inline char const *Exception::what() const noexcept(true)
{
    return d_what.c_str();
}
        
#endif




