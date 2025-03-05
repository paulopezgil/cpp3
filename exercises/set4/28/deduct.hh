#ifndef DEDUCT_HH
#define DEDUCT_HH

// 1st variant: plain template type
template <typename Type>
struct Deduct
{
    enum { value = 1 };
};

// 2nd variant: pointer to a type
template <typename Type>
struct Deduct<Type *>
{
    enum { value = 2 };
};

// 3rd variant: reference to a type
template <typename Type>
struct Deduct<Type &>
{
    enum { value = 3 };
};

// 4th variant: rvalue reference to a type
template <typename Type>
struct Deduct<Type &&>
{
    enum { value = 4 };
};

#endif