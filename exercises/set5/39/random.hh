#ifndef RND_IT_HH
#define RND_IT_HH

#include "bidirectional.i"
#include <concepts>

template <typename Type>
concept RndIterator = BiIterator<Type> and
    requires(Type lhs, Type rhs)
    {
        { lhs += 0 } -> std::same_as<Type &>;
        { lhs -= 0 } -> std::same_as<Type &>;
        { lhs + 0 } -> std::same_as<Type>;
        { lhs - 0 } -> std::same_as<Type>;
        { lhs - rhs } -> std::same_as<long int>;
    };

#endif