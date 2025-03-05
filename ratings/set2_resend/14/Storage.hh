#ifndef STORAGE_HH
#define STORAGE_HH

#include <vector>

template <typename Data>
class Storage
{
    std::vector<Data *> d_storage;
    
    public:
        class iterator;
        class reverse_iterator;
        
        iterator begin();
        iterator end();
        reverse_iterator rbegin();
        reverse_iterator rend();
};

#include "iterator.i"   // implementation of Storage<Data>::iterator
#include "reverse.i"    // implementation of Storage<Data>::reverse_iterator

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