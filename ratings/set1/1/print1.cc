#include "main.ih"

string (*sum1)(string const &, string const &) = add;

void print1()
{
    cout << reinterpret_cast<void *>(sum1) << '\n';
}