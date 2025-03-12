#ifndef BASIC_MATH_HH
#define BASIC_MATH_HH

// definition of BasicMath concept
template <typename T1, typename T2>
concept BasicMath =
    requires(T1 arg1, T2 arg2)
    {
        arg1 + arg2;
        arg1 - arg2;
        arg1 * arg2;
        arg1 / arg2;
        -arg1;
        -arg2;
    };

// just an empty function template parameter that requires BasicMath
template <typename T1, typename T2> requires BasicMath<T1, T2>
void fun(T1 arg1, T2 arg2) {};

#endif