// In this implementation, we are not assuming that the types of
// the operands are equal

#ifndef NEST_HH
#define NEST_HH

template <typename Lhs, typename Rhs>
concept Addable =
    requires(Lhs lhs, Rhs rhs)
    {
        lhs + rhs;
        lhs - rhs;
    };

template <typename Lhs, typename Rhs>
concept Multipliable =
    requires(Lhs lhs, Rhs rhs)
    {
        lhs * rhs;
        lhs / rhs;
    };

template <typename Lhs, typename Rhs>
concept AddMul = Addable<Lhs, Rhs> or Multipliable<Lhs, Rhs>;

template <typename Lhs, typename Rhs>
concept AddOrMul = (Addable<Lhs, Rhs> and not Multipliable<Lhs, Rhs>) or
                   (Multipliable<Lhs, Rhs> and not Addable<Lhs, Rhs>);

#endif