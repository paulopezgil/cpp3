#include "Scanner.ih"

void Scanner::openFile(std::string const &filename)
{
    // check for recursive inclusion
    if (d_included.find(filename) != d_included.end())
        throw std::runtime_error("Recursive inclusion\n");
    
    // save the file name
    d_included.insert(filename);
        
    // open the file
    pushStream(filename);

    // return to initial condition
    begin(StartCondition_::INITIAL);
}