// should be a .hh file
#ifndef OUT_IT_HH
#define OUT_IT_HH

#include "common.i"

template <typename Type>
concept OutIterator = Comparable<Type> and 
                     Incrementable<Type> and
                     Dereferenceable<Type>;

#endif