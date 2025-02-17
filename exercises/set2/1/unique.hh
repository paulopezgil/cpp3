#ifndef UNIQUE_HH_
#define UNIQUE_HH_

#include <memory>

template <typename Type>
class Unique
{
    std::unique_ptr<Type> d_ptr;

    public:
        // default, copy and move constructor
        Unique() = default; // uses default constructor of unique_ptr
        Unique(Unique const &other);
        Unique(Unique &&tmp) = default; // uses move constructor of unique_ptr

        // constructors accepting Types
        Unique(Type const &tp);
        Unique(Type *ptr);

        // copy and move assignment
        Unique &operator=(Unique const &other);
        Unique &operator=(Unique &&other) = default; // uses unique_ptr default
                                                    // move assignment
        // get members
        Type &get();
        Type const &get() const;
};

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

#include "unique.ii"
#endif