#ifndef FORWARDER_HH_
#define FORWARDER_HH_

#include <utility>

template <typename Fun, typename ...Args>
void forwarder(Fun &&fun, Args &&...args)
{
    // Call the function with the perfectly forwarded arguments
    fun(std::forward<Args>(args)...);
}

#endif