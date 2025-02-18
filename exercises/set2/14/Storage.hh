#ifndef STORAGE_HH
#define STORAGE_HH

#include <vector>

template <typename Data>
class Storage
{
    std::vector<Data *> d_storage;
    
    public:
        using iterator = std::vector<Data *>::iterator;
        using reverse_iterator = std::vector<Data *>::reverse_iterator;
        
        iterator begin();
        iterator end();
        reverse_iterator rbegin();
        reverse_iterator rend();
};

template<typename Data>
inline typename Storage<Data>::iterator Storage<Data>::begin()
{
    return d_storage.begin();
}

template<typename Data>
inline typename Storage<Data>::iterator Storage<Data>::end()
{
    return d_storage.end();
}

template<typename Data>
inline typename Storage<Data>::reverse_iterator Storage<Data>::rbegin()
{
    return d_storage.rbegin();
}

template<typename Data>
inline typename Storage<Data>::reverse_iterator Storage<Data>::rend()
{
    return d_storage.rend();
}

#endif