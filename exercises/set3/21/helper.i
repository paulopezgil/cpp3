#include <type_traits>

template <typename Needle, typename First, typename ...Types>
struct Helper
{
    enum
    {
        value = std::is_same<Needle, First>::value ? 
                                        1 : 1 + Helper<Needle, Types...>::value
    };
};

template <typename Needle, typename First>
struct Helper<Needle, First>
{
    enum { value = std::is_same<Needle, First>::value };
};