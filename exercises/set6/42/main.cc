#include "scanner/Scanner.h"

int main()
{
    Scanner scanner;

    // read all the lines from cin
    scanner.lex();

    // print the tokenized lines
    scanner.printResults();
}