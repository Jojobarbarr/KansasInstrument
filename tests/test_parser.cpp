#include <basic/lexer.h>
#include <basic/parser.h>
#include <iostream>

int main()
{
    CustomString input( "1 + 2" );
    Lexer lexer;
    lexer.init( input );
    Parser parser( lexer.words_ );

    return 0;
}