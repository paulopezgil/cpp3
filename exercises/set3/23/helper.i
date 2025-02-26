#include <type_traits>

template <typename Needle, typename ...Types>
template <typename NeedleIdx, typename FirstIdx, typename ...TypesIdx>
struct Type<Needle, Types...>::TypeIdx 
{
    enum
    {
        value = std::is_same<NeedleIdx, FirstIdx>::value ? 
                                    1 : 1 + TypeIdx<NeedleIdx, TypesIdx...>::value
    };
};

template <typename Needle, typename ...Types>
template <typename NeedleIdx, typename FirstIdx>
struct Type<Needle, Types...>::TypeIdx<NeedleIdx, FirstIdx>
{
    enum { value = std::is_same<NeedleIdx, FirstIdx>::value };
};