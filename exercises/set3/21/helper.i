#include <type_traits>

template <typename Needle, typename First, typename ...Types>
struct TypeIdx 
{
    enum
    {
        value = std::is_same<Needle, First>::value ? 
                                    1 : 1 + TypeIdx<Needle, Types...>::value
    };
};

template <typename Needle, typename First>
struct TypeIdx<Needle, First>
{
    enum { value = std::is_same<Needle, First>::value };
};