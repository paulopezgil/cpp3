#include "./storage/storage.hh"
#include <iostream>


int main()
{
    Storage storage = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; // Example values

    std::cout << storage[Icmp::ID]         << '\n'  // Access via enum class
              << storage[TcpUdp::PROTOCOL] << '\n'  // Access via another enum class
              << storage[2]                << '\n' // Access via integer
              //<< storage['a']              << '\n'  // Access via char (ASCII conversion)
              << storage[12.5]             << '\n'; // Access via double (implicit conversion)

}
