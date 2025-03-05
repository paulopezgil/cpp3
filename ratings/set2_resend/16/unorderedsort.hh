// JB: 0
#ifndef UNORDERED_SORT_HH
#define UNORDERED_SORT_HH


#include <unordered_map>
#include <algorithm>
#include <map>


// Class declaration
template <typename KeyT, typename ValT>
class UnorderedSort
{
    std::unordered_map<KeyT, ValT> d_umap;
    // JB: This doubles the requires storage. That's not very efficient, and
    // JB: the larger key or value types are, the worse it gets.
    std::map<KeyT, ValT> d_map;

    public:
        // Copy construct from an unordered_map
        UnorderedSort(std::unordered_map<KeyT, ValT> const &other);

        // return the original unordered_map
        std::unordered_map<KeyT, ValT> const &map() const;

        // return the unordered_map in a sorted way
        std::map<KeyT, ValT> const &sort() const;

        // return the unordered_map sorted with a custom comparison criteria
        template<class Compare>
        std::map<KeyT, ValT, Compare> const &sort(Compare comp);
};

template <typename KeyT, typename ValT>
inline UnorderedSort<KeyT, ValT>::UnorderedSort(
                                std::unordered_map<KeyT, ValT> const &other)
:
    d_umap(other),
    d_map(other.begin(), d_map.end())
{}

template <typename KeyT, typename ValT>
inline std::unordered_map<KeyT, ValT> const &
UnorderedSort<KeyT, ValT>::map() const
{
    return d_umap;
}

template <typename KeyT, typename ValT>
inline std::map<KeyT, ValT> const &UnorderedSort<KeyT, ValT>::sort() const
{
    return d_map;
}

template <typename KeyT, typename ValT>
template<class Compare>
std::map<KeyT, ValT, Compare> const &
UnorderedSort<KeyT, ValT>::sort(Compare comp)
{
    // first, sort the map with the custom comparison criteria
    std::sort(d_map.begin(), d_map.end(), comp);

    // then, return the newly sorted map
    return d_map;
}


#endif
