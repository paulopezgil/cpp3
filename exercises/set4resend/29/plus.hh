// JB: 1
//JB: Indeed, a function object would be nice.
#ifndef PLUS_HH
#define PLUS_HH


template <typename Type>
struct plus
{
    plus() = default; // JB: Quite SF

    Type operator()(Type lhs, Type rhs);
};

template <typename Type>
Type plus<Type>::operator()(Type lhs, Type rhs)
{
    return lhs + rhs;
}


#endif
