// should be a .hh file
#ifndef BI_IT_HH
#define BI_IT_HH

#include "forward.i"
#include <concepts>

template <typename Type>
concept BiIterator = FwdIterator<Type> and
    requires(Type type)
    {
        { --type } -> std::same_as<Type &>;
        { type-- } -> std::same_as<Type>;
    };

#endif