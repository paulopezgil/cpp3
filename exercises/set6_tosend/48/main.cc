int main(int argc, char *argv[])
try
{
    // a file name must be provided
    if (argc != 2)
        throw std::runtime_error("Please specify a file name\n");

    // initialize the scanner
    Scanner scanner;
    scanner.switchIstream(argv[1]);

    // read the input file
    scanner.lex();
}
catch(std::runtime_error exc)
{
    cerr << "Program ended after catching an exception: " << exc.what();
}