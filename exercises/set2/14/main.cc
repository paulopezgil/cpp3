#include "Storage.hh"
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    Storage<std::string> storage;

    sort(storage.begin(), storage.end());
    sort(storage.rbegin(), storage.rend());
}