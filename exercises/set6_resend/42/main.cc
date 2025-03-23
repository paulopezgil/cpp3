#include "scanner/Scanner.h"
#include <iostream>

int main()
{
    Scanner scanner;

    // process the lines according to the rules we defined
    std::cout << "Line 1\n";
    scanner.lex();
}