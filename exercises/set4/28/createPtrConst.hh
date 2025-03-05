template <typename Type>
auto const *createPtr(Type &&arg)
{
    Type *ptr = &arg;
    return ptr;
}