#include "data.hh"
#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;

int main()
{
    // use copy generic algorithm to fill a Data object with lines from cin.
    Data obj;
    copy(istream_iterator<string>(cin), istream_iterator<string>(), 
}