#ifndef DEDUCT_HH
#define DEDUCT_HH


// 1st variant: plain template type
template <typename Type>
struct Deduct
{
    enum { value = 1 };
    using value_type = Type;
};

// 2nd variant: pointer to a type
template <typename Type>
struct Deduct<Type *>
{
    enum { value = 2 };
    using value_type = Type;
};

// 3rd variant: reference to a type
template <typename Type>
struct Deduct<Type &>
{
    enum { value = 3 };
    using value_type = Type;
};

// 4th variant: rvalue reference to a type
template <typename Type>
struct Deduct<Type &&>
{
    enum { value = 4 };
    using value_type = Type;
};


#endif