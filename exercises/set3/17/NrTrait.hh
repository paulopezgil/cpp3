#ifndef NR_TRAIT_HH
#define NR_TRAIT_HH

template <int Nr>
struct NrTrait
{
    enum
    {
        value = Nr,
        absolute = Nr < 0 ? -Nr : Nr,
        even = Nr % 2 == 0,
        by3 = Nr % 3 == 0,
        sum_of_digits = absolute < 10 ? absolute 
                      : absolute % 10 + NrTrait<absolute / 10>::sum_of_digits,
        width = absolute < 10 ? 1 : 1 + NrTrait<absolute / 10>::width
    };
};

// specialization for case Nr = 0, needed for the recursion
template <>
struct NrTrait<0>
{
    enum
    {
        value = 0,
        absolute = 0,
        even = 1,
        by3 = 1,
        sum_of_digits = 0,
        width = 1
    };
};

#endif