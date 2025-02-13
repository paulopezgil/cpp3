template<typename Type>
std::ostream &operator<<(std::ostream &out, std::set<Type> const &nSet)
{
    out << '{';
    bool first = true;
    for (auto const &item : nSet)
    {
        if (!first)
            out << ", ";
        first = false;
        out << item;
    }
    out << '}';
    return out;
}