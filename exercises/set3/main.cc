#include "NrTrait.hh"
#include <iostream>

int main()
{
    // showing in a single cout statement what the value, evenness, 
    // divisibility by 3 and width is of the value -1971962
    std::cout << "value: " << NrTrait<-1971962>::value << '\n'
              << "absolute value: " << NrTrait<-1971962>::absolute << '\n'
              << "even: " << NrTrait<-1971962>::even << '\n'
              << "divisible by 3: " << NrTrait<-1971962>::by3 << '\n'
              << "sum of digits: " << NrTrait<-1971962>::sum_of_digits << '\n'
              << "width: " << NrTrait<-1971962>::width << '\n';
}