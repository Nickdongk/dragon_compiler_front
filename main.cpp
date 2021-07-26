#include <iostream>

#include "lexer.h"
#include "parser.h"

int main(int argc, char *argv[])
{
    Lexer *lex = new Lexer();
    Parser *parse = new lex();

    parse.program();
    cout << "\n";
}
