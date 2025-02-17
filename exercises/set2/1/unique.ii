#include "unique.hh"
#include "assignment.ii"

template <typename Type>
inline Unique<Type>::Unique(Unique const &other)
:
    d_ptr(new Type{*(other.d_ptr)})
{}

template <typename Type>
inline Unique<Type>::Unique(Type const &tp)
:
    d_ptr(new Type{tp})
{}

template <typename Type>
inline Unique<Type>::Unique(Type *ptr)
:
    d_ptr(ptr)
{}

template <typename Type>
inline Type &Unique<Type>::get()
{
    return *d_ptr;
}

template <typename Type>
inline Type const &Unique<Type>::get() const
{
    return *d_ptr;
}