// should be a .hh file
#ifndef FWD_IT_HH
#define FWD_IT_HH

#include "input.i"
#include "output.i"

template <typename Type>
concept FwdIterator = InIterator<Type> or OutIterator<Type>;

#endif