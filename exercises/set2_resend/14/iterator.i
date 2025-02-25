template <typename Data>
class Storage<Data>::iterator
{
    typename std::vector<Data *>::iterator d_it;

    public:
        // Iterator traits required by STL
        using iterator_category = std::random_access_iterator_tag;
        using value_type = Data;
        using difference_type = std::ptrdiff_t;
        using pointer = Data *;
        using reference = Data &;

        // Required RandomAccessIterator operators
        iterator(typename std::vector<Data *>::iterator it);
        iterator &operator++();
        iterator operator++(int);
        iterator &operator--();
        iterator operator--(int);
        bool operator==(iterator const &other) const;
        bool operator!=(iterator const &other) const;
        Data &operator*();

        // Additional operators required for random access iterators
        bool operator<(iterator const &other) const;
        bool operator>(iterator const &other) const;
        bool operator<=(iterator const &other) const;
        bool operator>=(iterator const &other) const;
        iterator &operator+=(difference_type num);
        iterator operator+(difference_type num) const;
        iterator &operator-=(difference_type num);
        iterator operator-(difference_type num) const;
        difference_type operator-(iterator const &other) const;
        reference operator[](difference_type num) const;
};

template <typename Data>
inline Storage<Data>::iterator::iterator(
                                    typename std::vector<Data *>::iterator it)
:
    d_it(it)
{}

template <typename Data>
inline typename Storage<Data>::iterator &Storage<Data>::iterator::operator++()
{
    ++d_it;
    return *this;
}

template <typename Data>
inline typename Storage<Data>::iterator
Storage<Data>::iterator::operator++(int)
{
    return iterator(d_it++);
}

template <typename Data>
inline typename Storage<Data>::iterator &Storage<Data>::iterator::operator--()
{
    --d_it;
    return *this;
}

template <typename Data>
inline typename Storage<Data>::iterator
Storage<Data>::iterator::operator--(int)
{
    return iterator(d_it--);
}

template <typename Data>
inline bool Storage<Data>::iterator::operator==(iterator const &other) const
{
    return d_it == other.d_it;
}

template <typename Data>
inline bool Storage<Data>::iterator::operator!=(iterator const &other) const
{
    return d_it != other.d_it;
}

template <typename Data>
inline Data &Storage<Data>::iterator::operator*()
{
    return **d_it;
}

template <typename Data>
inline bool Storage<Data>::iterator::operator<(iterator const &other) const
{ 
    return d_it < other.d_it; 
}

template <typename Data>
inline bool Storage<Data>::iterator::operator>(iterator const &other) const
{ 
    return d_it > other.d_it; 
}

template <typename Data>
inline bool Storage<Data>::iterator::operator<=(iterator const &other) const
{ 
    return d_it <= other.d_it; 
}

template <typename Data>
inline bool Storage<Data>::iterator::operator>=(iterator const &other) const
{ 
    return d_it >= other.d_it; 
}

template <typename Data>
inline typename Storage<Data>::iterator &
Storage<Data>::iterator::operator+=(difference_type num)
{ 
    d_it += num; 
    return *this; 
}

template <typename Data>
inline typename Storage<Data>::iterator
Storage<Data>::iterator::operator+(difference_type num) const
{ 
    return iterator(d_it + num); 
}

template <typename Data>
inline typename Storage<Data>::iterator &
Storage<Data>::iterator::operator-=(difference_type num)
{ 
    d_it -= num; 
    return *this; 
}

template <typename Data>
inline typename Storage<Data>::iterator 
Storage<Data>::iterator::operator-(difference_type num) const 
{ 
    return iterator(d_it - num); 
}

template <typename Data>
inline typename Storage<Data>::iterator::difference_type
Storage<Data>::iterator::operator-(iterator const &other) const
{ 
    return d_it - other.d_it; 
}

template <typename Data>
inline typename Storage<Data>::iterator::reference
Storage<Data>::iterator::operator[](difference_type num) const
{ 
    return **(d_it + num); 
}