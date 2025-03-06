#include "createPtr.hh"
#include <iostream>
using namespace std;

int main()
{
    int v1 = 1111;
    int *v2 = 0;
    int &v3 = v1;
    int &&v4 = 2;

    // show 1, 2, 3, 4 to cout
    cout << Deduct<decltype(v1)>::value << ' '
         << Deduct<decltype(v2)>::value << ' '
         << Deduct<decltype(v3)>::value << ' '
         << Deduct<decltype(v4)>::value << '\n';

    // creating a ptr to a const int
    int const v5 = 0;
    auto ptr = createPtr(v5);
    ptr = &v1;
    cout << *ptr << '\n';
}