#include <vector>

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

class Storage
{
    std::vector<size_t> d_data;

public:
    Storage() = default;
    Storage(std::initializer_list<size_t> const &list) : d_data(list) {}

    // Generic index operator
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