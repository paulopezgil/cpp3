//JB: 0

//JB: Always test your templates. I added this main program, and it does not
//JB: even compile. Therefore WC.

#include "storage.hh"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "specify some arguments\n";
        return 1;
    }

    Storage<string> storage;

    while (*argv)
        storage.push_back(new string{ *argv++ });

    cout << '\n';
    cout << storage.begin()->length() << ' ' << *storage.begin() << '\n';

    sort(storage.begin(), storage.end());
    copy(storage.begin(), storage.end(), ostream_iterator<string>(cout, " "));

    cout << "\n======\n";

    sort(storage.rbegin(), storage.rend());
    copy(storage.begin(), storage.end(), ostream_iterator<string>(cout, " "));

    cout << '\n';
}


//JB: Actually, not even this would compile:

// int main()
// {
//     Storage<double> doubles;
//     for (auto item: doubles)
//         std::cout << item << '\n';
// }
