template <typename Data>
class Storage<Data>::reverse_iterator
{
    typename std::vector<Data *>::reverse_iterator d_rit;

    public:
        // Iterator traits required by STL
        using iterator_category = std::random_access_iterator_tag;
        using value_type = Data;
        using difference_type = std::ptrdiff_t;
        using pointer = Data*;
        using reference = Data&;

        // Required RandomAccessIterator operators
        reverse_iterator(typename std::vector<Data *>::reverse_iterator rit);
        reverse_iterator &operator++();
        reverse_iterator operator++(int);
        reverse_iterator &operator--();
        reverse_iterator operator--(int);
        bool operator==(reverse_iterator const &other) const;
        bool operator!=(reverse_iterator const &other) const;
        Data &operator*();

        // Additional operators required for random access iterators
        bool operator<(reverse_iterator const &other) const;
        bool operator>(reverse_iterator const &other) const;
        bool operator<=(reverse_iterator const &other) const;
        bool operator>=(reverse_iterator const &other) const;
        reverse_iterator &operator+=(difference_type num);
        reverse_iterator operator+(difference_type num) const;
        reverse_iterator &operator-=(difference_type num);
        reverse_iterator operator-(difference_type num) const;
        difference_type operator-(reverse_iterator const &other) const;
        reference operator[](difference_type num) const;
};

template <typename Data>
Storage<Data>::reverse_iterator::reverse_iterator(
                        typename std::vector<Data *>::reverse_iterator rit)
:
    d_rit(rit)
{}

template <typename Data>
inline typename Storage<Data>::reverse_iterator &
Storage<Data>::reverse_iterator::operator++()
{
    ++d_rit;
    return *this;
}

template <typename Data>
inline typename Storage<Data>::reverse_iterator
Storage<Data>::reverse_iterator::operator++(int)
{
    reverse_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename Data>
inline typename Storage<Data>::reverse_iterator &
Storage<Data>::reverse_iterator::operator--()
{
    --d_rit;
    return *this;
}

template <typename Data>
inline typename Storage<Data>::reverse_iterator
Storage<Data>::reverse_iterator::operator--(int)
{
    reverse_iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename Data>
inline bool Storage<Data>::reverse_iterator::operator==(
                                        reverse_iterator const &other) const
{
    return d_rit == other.d_rit;
}

template <typename Data>
inline bool Storage<Data>::reverse_iterator::operator!=(
                                        reverse_iterator const &other) const
{
    return d_rit != other.d_rit;
}

template <typename Data>
inline Data &Storage<Data>::reverse_iterator::operator*()
{
    return **d_rit;
}

template <typename Data>
inline bool Storage<Data>::reverse_iterator::operator<(
                                        reverse_iterator const &other) const
{ 
    return d_rit < other.d_rit; 
}

template <typename Data>
inline bool Storage<Data>::reverse_iterator::operator>(
                                        reverse_iterator const &other) const
{ 
    return d_rit > other.d_rit; 
}

template <typename Data>
inline bool Storage<Data>::reverse_iterator::operator<=(
                                        reverse_iterator const &other) const
{ 
    return d_rit <= other.d_rit; 
}

template <typename Data>
inline bool Storage<Data>::reverse_iterator::operator>=(
                                        reverse_iterator const &other) const
{ 
    return d_rit >= other.d_rit; 
}

template <typename Data>
inline typename Storage<Data>::reverse_iterator &
Storage<Data>::reverse_iterator::operator+=(difference_type num)
{ 
    d_rit += num; 
    return *this; 
}

template <typename Data>
inline typename Storage<Data>::reverse_iterator
Storage<Data>::reverse_iterator::operator+(difference_type num) const
{ 
    return reverse_iterator(d_rit + num); 
}

template <typename Data>
inline typename Storage<Data>::reverse_iterator &
Storage<Data>::reverse_iterator::operator-=(difference_type num)
{ 
    d_rit -= num; 
    return *this; 
}

template <typename Data>
inline typename Storage<Data>::reverse_iterator 
Storage<Data>::reverse_iterator::operator-(difference_type num) const 
{ 
    return reverse_iterator(d_rit - num); 
}

template <typename Data>
inline typename Storage<Data>::reverse_iterator::difference_type
Storage<Data>::reverse_iterator::operator-(reverse_iterator const &other) const
{ 
    return d_rit - other.d_rit; 
}

template <typename Data>
inline typename Storage<Data>::reverse_iterator::reference
Storage<Data>::reverse_iterator::operator[](difference_type num) const
{ 
    return **(d_rit + num); 
}