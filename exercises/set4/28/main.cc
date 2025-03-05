#include "deduct.hh"
#include <iostream>
using namespace std;

int main()
{
    int a = 0;
    int *b = 0;
    int &c = a;
    int &&d = 0;

    // show 1, 2, 3, 4 to cout
    cout << Deduct<decltype(a)>::value << ' '
         << Deduct<decltype(b)>::value << ' '
         << Deduct<decltype(c)>::value << ' '
         << Deduct<decltype(d)>::value << '\n';

    // creating a ptr to a const int
    int const e = 0;
    auto ptr = createPtr(e);
    ptr = &a;
    cout << *ptr << '\n';
}