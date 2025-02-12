
enum class TcpUdp
{
    SECONDS = 1,
    MU_SECONDS,
    PROTOCOL,
    SRC,
    DST,
    SPORT,
    DPORT,
    SENTPACKETS,
    SENTBYTES,
    RECVDPACKETS,
    RECVDBYTES,
    nFields,
};

enum class Icmp
{
    SECONDS = 1,
    MU_SECONDS,
    SRC,
    DST,
    ID,
    SENTPACKETS,
    SENTBYTES,
    RECVDPACKETS,
    RECVDBYTES,
    nFields,
};

#include <iostream>
#include <vector>
#include <initializer_list>

class Storage
{
    std::vector<size_t> d_data;

public:
    Storage() = default;
    Storage(std::initializer_list<size_t> const &list) : d_data(list) {}

    // Generic index operator - works for enum classes, numbers, characters, etc.
    template <typename TIndex>
    size_t operator[](TIndex idx) const
    {
        return d_data.at(static_cast<size_t>(idx));  // Use at() for bounds checking
    }

    template <typename TIndex>
    size_t &operator[](TIndex idx)
    {
        return d_data.at(static_cast<size_t>(idx));
    }
};


int main()
{
    Storage storage = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; // Example values

    std::cout << storage[Icmp::ID]         << '\n'  // Access via enum class
              << storage[TcpUdp::PROTOCOL] << '\n'  // Access via another enum class
              << storage[2]                << '\n' // Access via integer
              << storage['a']              << '\n'  // Access via char (ASCII conversion)
              << storage[12.5]             << '\n'; // Access via double (implicit conversion)

}
