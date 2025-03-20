#include "main.ih"

int main(int argc, char *argv[])
{
    // a file name must be provided
    if (argc != 2)
    {
        cout << "Please provide an file name\n";
        return 1;
    }

    // initialize the scanner
    Scanner scanner;
    
    // write to a tmp stringstream and read from the specified file
    stringstream tmp;
    scanner.switchOstream(tmp);
    scanner.switchIstream(argv[1]);
    
    // process the file
    scanner.lex();

    // override the file
    ofstream outpf { argv[1] };
    outpf << tmp.str();
}