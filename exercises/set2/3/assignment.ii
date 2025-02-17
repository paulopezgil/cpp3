template <typename Type>
Unique<Type> &Unique<Type>::operator=(Unique<Type> const &other)
{
    std::unique_ptr<Type> tmp{new Type{*(other.d_ptr)}};
    d_ptr.swap(tmp);
    return *this;
}