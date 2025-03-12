#ifndef RETURN_REFERENCE_HH
#define RETURN_REFERENCE_HH
#include <concepts>

template <typename Type>
concept ReturnReference =
    requires(Type cont)
    {
        { cont[0] } -> std::same_as<typename Type::value_type &>;
    };

#endif