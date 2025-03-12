//JB: 0
#ifndef CREATE_PTR_HH
#define CREATE_PTR_HH

#include "deduct/deduct.hh"

// create a null pointer to the underlying type
template <typename Type>
auto createPtr(Type const &arg)
{
    typename Deduct<Type>::value_type *ptr = 0;
    //JB: back door / constness violation.
    return ptr;
}


#endif
