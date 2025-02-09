#include "main.ih"

string (*sum2)(string const &, string const &) = add;

void print2()
{
    cout << reinterpret_cast<void *>(sum2) << '\n';
}