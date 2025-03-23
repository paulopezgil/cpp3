#include "main.ih"

int main(int argc, char *argv[])
{
    Scanner scanner;

    // if no file names are specified, read from cin
    if (argc == 1)
        scanner.lex();

    // otherwise, read from each file
    else for (int idx = 1; idx != argc; ++idx)
    {
        // open the file and switch scanner's input stream
        ifstream file{ argv[idx] };
        scanner.switchStreams(file);

        // read the file
        scanner.lex();
    }

    // print the readed words
    scanner.printWords();
}