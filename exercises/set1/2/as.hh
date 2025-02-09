template<typename RetType, typename ArgType>
RetType as(ArgType const &arg)
{
    return static_cast<RetType>(arg);
}
