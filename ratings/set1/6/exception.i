#include "exception.ih"

template <typename Type>
Exception &&operator<<(Exception &&in, Type const &arg)
{
    ostringstream oss;
    oss << arg;
    in.d_what += oss.str();
    return move(in);
}