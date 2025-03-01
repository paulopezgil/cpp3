#ifndef TYPE_HH
#define TYPE_HH


// general case: more than 1 template argument
template <typename Needle, typename ...Types>
class Type
{    
    template <typename NeedleIdx, typename FirstIdx, typename ...TypesIdx>
    struct TypeIdx;
    
    template <typename NeedleIdx, typename FirstIdx>
    struct TypeIdx<NeedleIdx, FirstIdx>;

    public:
        enum { located = TypeIdx<Needle, Types...>::value };
};

// definition of Helper class
#include "helper.i"

// base case: only 1 template argument
template <typename Needle>
struct Type<Needle>
{
    enum { located = 0 };
};


#endif