#ifndef UNORDERED_SORT_HH
#define UNORDERED_SORT_HH


#include <unordered_map>
#include <algorithm>
#include <map>


// Class declaration
template <typename KeyT, typename ValT>
class UnorderedSort
{
    std::unordered_map<KeyT, ValT> d_map;

    public:
        UnorderedSort(std::unordered_map<KeyT, ValT> const &other);

        std::unordered_map<KeyT, ValT> const &map() const;
        std::map<KeyT, ValT> sort() const;

        template<class Compare>
        std::map<KeyT, ValT, Compare> sort(Compare comp) const;
};

// Copy constructor
template <typename KeyT, typename ValT>
inline UnorderedSort<KeyT, ValT>::UnorderedSort(
                                std::unordered_map<KeyT, ValT> const &other)
:
    d_map(other)
{}

// accessor
template <typename KeyT, typename ValT>
inline std::unordered_map<KeyT, ValT> const &
UnorderedSort<KeyT, ValT>::map() const
{
    return d_map;
}

template <typename KeyT, typename ValT>
std::map<KeyT, ValT> UnorderedSort<KeyT, ValT>::sort() const
{
    return std::map<KeyT, ValT> {d_map.begin(), d_map.end()};
}

template <typename KeyT, typename ValT>
template<class Compare>
std::map<KeyT, ValT, Compare> UnorderedSort<KeyT, ValT>::sort(Compare comp) const
{
    return std::map<KeyT, ValT, Compare> {d_map.begin(), d_map.end()};
}





#endif