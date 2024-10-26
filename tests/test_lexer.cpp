#include <basic/custom_string.h>
#include <basic/lexer.h>
#include <iostream>

static size_t test_lexer()
{
    std::cout << "\n\ntest_lexer\n\n";
    CustomString inputs[6];
    inputs[0] = "1+275/50+1";
    inputs[1] = "1+ 275/50+1";
    inputs[2] = "23?7+7";
    inputs[3] = "0002+0034";
    inputs[4] = "230980000/23x1x1x1";
    inputs[5] = "23+";

    CustomString answers[6];
    answers[0] = "1 + 275 / 50 + 1 ";
    answers[1] = "1 +   275 / 50 + 1 ";
    answers[2] = "23 ? 7 + 7 ";
    answers[3] = "2 + 34 ";
    answers[4] = "230980000 / 23 x 1 x 1 x 1 ";
    answers[5] = "23 + ";

    for( size_t idx( 0 ); idx < 6; ++idx )
    {
        Lexer lexer;
        lexer.init( inputs[idx] );
        std::cout << "User input: " << inputs[idx] << "\n";
        std::cout << "Lexer ouput: " << lexer.output() << "\n";
        std::cout << "Expected output: " << answers[idx] << "\n\n";
        if( lexer.output() != answers[idx] )
        {
            return idx;
        }
        lexer.clear();
    }
    return 99999;
}

static size_t test_verify_words()
{
    std::cout << "\n\ntest_verify_words\n\n";
    CustomString inputs[6];
    inputs[0] = "1+275/50+1";
    inputs[1] = "1+ 275/50+1";
    inputs[2] = "23?7+7";
    inputs[3] = "0002+0034";
    inputs[4] = "230980000/23x1x1x1";
    inputs[5] = "23+";

    int answers[6]{};
    answers[0] = -1;
    answers[1] = 2;
    answers[2] = 1;
    answers[3] = -1;
    answers[4] = -1;
    answers[5] = -1;

    for( size_t idx( 0 ); idx < 6; ++idx )
    {
        Lexer lexer;
        lexer.init( inputs[idx] );
        std::cout << "User input: " << inputs[idx] << "\n";
        std::cout << "Lexer ouput: " << lexer.verify_words() << "\n";
        std::cout << "Expected output: " << answers[idx] << "\n\n";
        if( lexer.verify_words() != answers[idx] )
        {
            return idx;
        }
        lexer.clear();
    }
    return 99999;
}
static size_t test_verify_syntax()
{
    std::cout << "\n\ntest_verify_syntax\n\n";
    CustomString inputs[6];
    inputs[0] = "1+275/50+1";
    inputs[1] = "1++275/50+1";
    inputs[2] = "237+7x";
    inputs[3] = "-0002+0034";
    inputs[4] = "230980000/23xx1x1x1";
    inputs[5] = "234";

    int answers[6]{};
    answers[0] = 99999;
    answers[1] = 2;
    answers[2] = 4;
    answers[3] = 0;
    answers[4] = 4;
    answers[5] = 99999;

    for( size_t idx( 0 ); idx < 6; ++idx )
    {
        Lexer lexer;
        lexer.init( inputs[idx] );
        std::cout << "User input: " << inputs[idx] << "\n";
        std::cout << "Lexer ouput: " << lexer.verify_syntax() << "\n";
        std::cout << "Expected output: " << answers[idx] << "\n\n";
        if( lexer.verify_syntax() != answers[idx] )
        {
            return idx;
        }
        lexer.clear();
    }
    return 99999;
}
int main()
{
    size_t test_lexer_result( test_lexer() );
    if( test_lexer_result != 99999 )
    {
        std::cout << "Error for test_lexer for input[" << test_lexer_result
                  << "]\n";
        return 1;
    }
    size_t test_verify_words_result( test_verify_words() );
    if( test_verify_words_result != 99999 )
    {
        std::cout << "Error for test_verify_words for input["
                  << test_verify_words_result << "]\n";
        return 2;
    }
    size_t test_verify_syntax_result( test_verify_syntax() );
    if( test_verify_syntax_result != 99999 )
    {
        std::cout << "Error for test_verify_syntax for input["
                  << test_verify_syntax_result << "]\n";
        return 3;
    }
}
