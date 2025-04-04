#ifndef STORAGE_HH
#define STORAGE_HH

#include <vector>
#include "iterator/iterator.hh"   // implementation of the iterator class

template <typename Data>
class Storage
{
    std::vector<Data *> d_storage;
    
    public:
        using iterator = Iterator<Data, std::vector>;
        using reverse_iterator = std::reverse_iterator<iterator>;

        void push_back(Data *data);
        
        iterator begin();
        iterator end();
        reverse_iterator rbegin();
        reverse_iterator rend();
};

template <typename Data>
inline void Storage<Data>::push_back(Data *data)
{
    d_storage.push_back(data);
}

template <typename Data>
typename Storage<Data>::iterator Storage<Data>::begin()
{
    return iterator(d_storage.begin());
}

template <typename Data>
typename Storage<Data>::iterator Storage<Data>::end()
{
    return iterator(d_storage.end());
}

template <typename Data>
typename Storage<Data>::reverse_iterator Storage<Data>::rbegin()
{
    return reverse_iterator(d_storage.rbegin());
}

template <typename Data>
typename Storage<Data>::reverse_iterator Storage<Data>::rend()
{
    return reverse_iterator(d_storage.rend());
}

#endif