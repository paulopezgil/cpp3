// should be a .hh file
#ifndef IN_IT_HH
#define IN_IT_HH

#include "common.i"

template <typename Type>
concept InIterator = Comparable<Type> and 
                     Incrementable<Type> and
                     ConstDereferenceable<Type>;

#endif