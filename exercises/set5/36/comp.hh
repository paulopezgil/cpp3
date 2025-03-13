// definition of the comparable concept
template <typename Lhs, typename Rhs>
concept Comparable =
    requires(Lhs lhs, Rhs rhs)
    {
        lhs <=> rhs;
    };

// a function template that takes 2 comparables template type arguments
// could return -1 if lhs < rhs, 0 if lhs == rhs and 1 otherwise.
template <typename Lhs, typename Rhs> requires Comparable<Lhs, Rhs>
int compare(Lhs lhs, Rhs rhs);

// a class template that takes 1 comparable template type argument
template <typename Type> requires Comparable<Type, Type>
class Compare;