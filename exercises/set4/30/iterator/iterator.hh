#ifndef ITERATOR_HH
#define ITERATOR_HH
#define IteratorType Iterator<Data, Container>
#define IteratorType_ Iterator<Data_, Container_>

#include <iterator>

template <typename Data, template <typename> class Container>
struct Iterator
{
    typename Container<Data *>::iterator d_it;

    public:
        // Iterator traits required by STL
        using iterator_category = std::random_access_iterator_tag;
        using value_type = Data;
        using difference_type = std::ptrdiff_t;
        using pointer = Data *;
        using reference = Data &;

        // Required RandomAccessIterator operators
        Iterator &operator++();
        Iterator operator++(int);
        Iterator &operator--();
        Iterator operator--(int);
        bool operator!=(Iterator const &other) const;
        Data &operator*();

        // Additional operators required for random access Iterators
        Iterator &operator+=(difference_type num);
        Iterator operator+(difference_type num) const;
        Iterator &operator-=(difference_type num);
        Iterator operator-(difference_type num) const;
        reference operator[](difference_type num) const;

        // Missing members in last implementation
        Data *operator->();
        template <typename Data_, template <typename> class Container_>
        friend bool operator==(IteratorType_ const &lhs,
                               IteratorType_ const &rhs);      
        template <typename Data_, template <typename> class Container_>
        friend auto operator<=>(IteratorType_ const &lhs,
                                IteratorType_ const &rhs);
        template <typename Data_, template <typename> class Container_>
        friend typename IteratorType::difference_type 
        operator-(IteratorType_ const &lhs,
                  IteratorType_ const &rhs);
        Iterator(typename Container<Data *>::iterator const &current);
};

template <typename Data, template <typename> class Container>
inline IteratorType &IteratorType::operator++()
{
    ++d_it;
    return *this;
}

template <typename Data, template <typename> class Container>
inline IteratorType IteratorType::operator++(int)
{
    return IteratorType(d_it++);
}

template <typename Data, template <typename> class Container>
inline IteratorType &IteratorType::operator--()
{
    --d_it;
    return *this;
}

template <typename Data, template <typename> class Container>
inline IteratorType IteratorType::operator--(int)
{
    return IteratorType(d_it--);
}

template <typename Data, template <typename> class Container>
inline bool IteratorType::operator!=(IteratorType const &other) const
{
    return d_it != other.d_it;
}

template <typename Data, template <typename> class Container>
inline Data &IteratorType::operator*()
{
    return **d_it;
}

template <typename Data, template <typename> class Container>
inline IteratorType & IteratorType::operator+=(difference_type num)
{ 
    d_it += num; 
    return *this; 
}

template <typename Data, template <typename> class Container>
inline IteratorType IteratorType::operator+(difference_type num) const
{ 
    return IteratorType(d_it + num); 
}

template <typename Data, template <typename> class Container>
inline IteratorType &IteratorType::operator-=(difference_type num)
{ 
    d_it -= num; 
    return *this; 
}

template <typename Data, template <typename> class Container>
inline IteratorType IteratorType::operator-(difference_type num) const 
{ 
    return IteratorType(d_it - num); 
}

template <typename Data, template <typename> class Container>
inline IteratorType::reference
IteratorType::operator[](difference_type num) const
{ 
    return **(d_it + num); 
}

template <typename Data, template <typename> class Container>
inline Data *IteratorType::operator->()
{
    return *d_it;
}

template <typename Data, template <typename> class Container>
inline bool operator==(IteratorType const &lhs, IteratorType const &rhs)
{
    return lhs.d_it == rhs.d_it;
}

template <typename Data, template <typename> class Container>
inline auto operator<=>(IteratorType const &lhs, IteratorType const &rhs)
{
    return lhs.d_it <=> rhs.d_it;
}

template <typename Data, template <typename> class Container>
inline typename IteratorType::difference_type 
operator-(IteratorType const &lhs, IteratorType const &rhs)
{
    return lhs.d_it - rhs.d_it;
}

template <typename Data, template <typename> class Container>
inline IteratorType::Iterator(typename
                              Container<Data *>::iterator const &current)
:
    d_it(current)
{}


#undef IteratorType
#undef IteratorType_
#endif