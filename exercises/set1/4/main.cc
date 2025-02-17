// No main.ih for simplicity
#include "forwarder.hh"
#include <iostream>
using namespace std;

class Demo {};

// Skipping 1F1F rule for demonstration purposes
void fun(int first, int second)
{
    cout << "funny int\n";
}

void fun(Demo &&dem1, Demo &&dem2)
{
    cout << "funny Demo\n";
}

int main()
{
    // passing fun to forwarder recieving ints using pointers to functions
    void (*intFun)(int, int) = fun;
    forwarder(intFun, 1, 3);

    // passing fun to forwarder recieving Demos using pointers to functions
    void (*demoFun)(Demo &&, Demo &&) = fun;
    forwarder(demoFun, Demo{}, Demo{});

    // passing fun to forwarder recieving ints using static_cast
    forwarder(static_cast<void (*)(int, int)>(fun), 1, 3);

    // passing fun to forwarder recieving Demos using static_cast
    forwarder(static_cast<void (*)(Demo &&, Demo &&)>(fun), Demo{}, Demo{});
}