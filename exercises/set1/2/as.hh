#ifndef AS_HH_
#define AS_HH_

template <typename RetType, typename ArgType>
RetType as(ArgType const &arg)
{
    return static_cast<RetType>(arg);
}

#endif
