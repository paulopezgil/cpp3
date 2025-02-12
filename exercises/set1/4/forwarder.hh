#include <utility> // for std::forward

template <typename Fun, typename ...Args>
void forwarder(Fun fun, Args &&...args)
{
    // Call the function with the arguments
    fun()
}

void fun(int first, int second);
void fun2(Demo &&dem1, Demo &&dem2);
                                        // increments each argument:
void incrementer(int &one, int &two, int &three);

int main()
{
    forwarder(fun, 1, 3);       // should show 'fun(1, 3)' to cout

                                // fun2 expects two rvalue references 
    forwarder(fun2, Demo{}, Demo{});

    forwarder(plus<string>(), "hello ", "world");

    vector<int> first;
    forwarder(                  // receives a lambda function
        [](vector<int> &first, vector<int> const &second, 
                                vector<int> const &third)
        {
            // modify first's elements using second's and third's
            // elements
        }, first, vector<int>{}, vector<int>{}
    );

    int var = 0;
    forwarder(incrementer, var, var, var);
    cout << var << '\n';          // should show '3'
}