#ifndef COMMON_HH
#define COMMON_HH
#include <concepts>

template <typename Type>
concept Comparable =
    requires (Type lhs, Type rhs)
    {
        { lhs == rhs } -> std::same_as<bool>;
        { lhs != rhs } -> std::same_as<bool>;
    };

template <typename Type>
concept Dereferenceable =
    requires(Type type)
    {
        { *type } -> std::same_as<typename Type::value_type &>;
    };

template <typename Type>
concept ConstDereferenceable =
    requires(Type type)
    {
        // as suggested in the annotations
        { *type } ->  std::convertible_to<typename Type::value_type const &>;
    };

template <typename Type>
concept Incrementable =
    requires (Type type)
    {
        { ++type } -> std::same_as<Type &>;
        { type++ } -> std::same_as<Type>;
    };

#endif