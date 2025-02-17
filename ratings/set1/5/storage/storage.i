template <typename TIndex>
inline size_t Storage::operator[](TIndex idx) const
{
    // Use at() for bounds checking
    return d_data.at(static_cast<size_t>(idx));
}

template <typename TIndex>
inline size_t &Storage::operator[](TIndex idx)
{
    return d_data.at(static_cast<size_t>(idx));
}