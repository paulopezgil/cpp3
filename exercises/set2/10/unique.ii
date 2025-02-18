#include "unique.hh"
#include "assignment.ii"


template <typename Type>
inline size_t Unique<Type>::s_count = 0;

template <typename Type>
inline size_t Unique<Type>::s_actual = 0;


template <typename Type>
inline Unique<Type>::~Unique()
{
    --s_actual;
}

template <typename Type>
inline Unique<Type>::Unique()
{
    ++s_count;
    ++s_actual;
}

template <typename Type>
inline Unique<Type>::Unique(Unique const &other)
:
    d_ptr(new Type{*(other.d_ptr)})
{
    ++s_count;
    ++s_actual;
}

template <typename Type>
inline Unique<Type>::Unique(Unique &&tmp)
:
    d_ptr(std::move(tmp.d_ptr))
{
    ++s_count;
    ++s_actual;
}

template <typename Type>
inline Unique<Type>::Unique(Type const &tp)
:
    d_ptr(new Type{tp})
{
    ++s_count;
    ++s_actual;
}

template <typename Type>
inline Unique<Type>::Unique(Type *ptr)
:
    d_ptr(ptr)
{
    ++s_count;
    ++s_actual;
}

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

template <typename Type>
inline size_t Unique<Type>::actual() const
{
    return s_actual;
}

template <typename Type>
inline size_t Unique<Type>::count() const
{
    return s_count;
}
