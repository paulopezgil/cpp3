#ifndef MERGE_HH
#define MERGE_HH

#include"chars/chars.hh"
#include "onechar/onechar.hh"

// Forward declaration for the general case
template <typename LHS, typename RHS>
class Merge;

// Specialization for merging two Chars templates
template <char ...Lhs, char ...Rhs>
class Merge<Chars<Lhs...>, Chars<Rhs...>>
{
    public:
        using CP = Chars<Lhs..., Rhs...>;
};

// Specialization for merging a Chars template with a OneChar template
template <char ...Lhs, char Rhs>
class Merge<Chars<Lhs...>, OneChar<Rhs>>
{
    public:
        using CP = Chars<Lhs..., Rhs>;
};

#endif