#include "basicmath.hh"
#include <string>

int main()
{
    int x = 0, y = 1;
    fun(x, y);

    // Example to demonstrate that the compiler complains when the operations
    // listed in BasicMath can't be performed by the 2 types
    // int num = 1;
    // std::string str = "abcd";
    // fun(num, str);
}