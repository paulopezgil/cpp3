#include "Scanner.h"

void Scanner::printWords()
{
    while(d_words.size() != 0)
    {
        std::cout << d_words.top() << ' ';
        d_words.pop();
    }
}