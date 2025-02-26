#include <iostream>
#include "type.hh"

// for showing that the output is the same as before
int main()
{
    std::cout <<
        Type<int>::located << ' ' << 
        Type<int, double>::located << ' ' << 
        Type<int, int>::located << ' ' << 
        Type<int, double, int>::located << ' ' << 
        Type<int, double, int>::located << ' ' << 
        Type<int, double, int, int, int>::located << 
        '\n';
}