#include "Scanner.ih"

void Scanner::printResults()
{
    Tokenizer tokenizer;

    for(size_t idx = 0; idx != d_lines.size(); ++idx)
    {
        cout << "line " << idx << ":\n";

        // process each line as an input string stream
        std::istringstream line { d_lines[idx] };
        tokenizer.switchStreams(line);

        // read the file
        while(size_t token = tokenizer.lex())
        {
            string const &text = tokenizer.matched();
            switch(token)
            {
                case Tokenizer::WORD:
                    cout << "identifier: " << text << '\n';
                break;
                case Tokenizer::INTEGER:
                    cout << "integer: " << text << '\n';
                break;
                case Tokenizer::REAL:
                    cout << "real: " << text << '\n';
                break;
                case Tokenizer::STRING:
                    cout << "string: " << text << '\n';
                break;
                case Tokenizer::OPERATOR:
                    cout << "operator: " << text << '\n';
                break;
                default:
                    cout << static_cast<int>(text[0]) << ": " << text << "'\n";
                break;
            }

        }
    }
}