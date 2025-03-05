#ifndef PLUS_HH
#define PLUS_HH


template <typename Type>
struct plus
{
    plus() = default;

    Type operator()(Type lhs, Type rhs);
};

template <typename Type>
Type plus<Type>::operator()(Type lhs, Type rhs)
{
    return lhs + rhs;
}


#endif