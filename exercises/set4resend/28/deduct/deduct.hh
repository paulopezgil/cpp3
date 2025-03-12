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
/* JB: Naming.
   *What* does this struct deduce?
   I do suppose you meant: "Deduce"?
   To deduct: to subtract an amount from a total.
   To deduce: to draw a conclusion.
   The deverbal noun is the same in both cases, but the verb is not.
   Both derive from Latin 'de' - away, and 'ducere' - to lead.
 */
