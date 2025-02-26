#ifndef TYPE_HH
#define TYPE_HH

// definition of Helper class
#include "helper.i"

// general case: more than 1 template argument
template <typename Needle, typename ...Types>
struct Type
{
    enum { located = Helper<Needle, Types...>::value };
};

// base case: only 1 template argument
template <typename Needle>
struct Type<Needle>
{
    enum { located = 0 };
};


#endif