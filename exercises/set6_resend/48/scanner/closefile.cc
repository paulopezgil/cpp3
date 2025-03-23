#include "Scanner.ih"

void Scanner::closeFile()
{
    // If the stream is the initial one, return.
    if (not popStream())
        return;
    
    // Otherwise, continue reading the previous stream
    begin(StartCondition_::INCLUDE);
}