#include <basic/custom_string.h>
#include <basic/lexer.h>
#include <basic/node.h>
#include <basic/parser.h>
#include <iostream>

bool check_vocabulary( const Lexer& lexer )
{
    int verify_words_result( lexer.verify_words() );
    if( verify_words_result != -1 )
    {
        std::cout << "Invalid input:\n";
        std::cout << lexer.output() << "\n";
        for( size_t word_index( 0 ); word_index < lexer.words_.size();
             ++word_index )
        {
            if( word_index == verify_words_result )
            {
                std::cout << "^\n";
                break;
            }
            else
            {
                size_t word_length(
                    lexer.words_[word_index]->value().length() );
                for( size_t char_index( 0 ); char_index < word_length;
                     ++char_index )
                {
                    std::cout << " ";
                }
                std::cout << " ";
            }
        }
        std::cout << "Character " << lexer.words_[verify_words_result]->value()
                  << " is invalid.\n";
        return false;
    }
    return true;
}

bool check_syntax( const Lexer& lexer )
{
    size_t verify_syntax_result( lexer.verify_syntax() );
    if( verify_syntax_result != 99999 )
    {
        std::cout << "Invalid input:\n";
        std::cout << lexer.output() << "\n";
        for( size_t word_index( 0 ); word_index <= lexer.words_.size();
             ++word_index )
        {
            if( word_index == verify_syntax_result )
            {
                std::cout << "^\n";
                break;
            }
            else
            {
                size_t word_length(
                    lexer.words_[word_index]->value().length() );
                for( size_t char_index( 0 ); char_index < word_length;
                     ++char_index )
                {
                    std::cout << " ";
                }
                std::cout << " ";
            }
        }
        std::cout << "Syntax error. Please ensure your formula is correct.\n";
        return false;
    }
    return true;
}

int main()
{
    std::cout << " _____________________\n"
              << "|  _________________  |\n"
              << "| |              0. | |\n"
              << "| |_________________| |\n"
              << "|  ___ ___ ___   ___  |\t\t KansasInstrument\n"
              << "| | 7 | 8 | 9 | | + | |\n"
              << "| |___|___|___| |___| |\t\t    Calculator will be back.\n"
              << "| | 4 | 5 | 6 | | - | |\n"
              << "| |___|___|___| |___| |\n"
              << "| | 1 | 2 | 3 | | x | |\n"
              << "| |___|___|___| |___| |\n"
              << "| |   | 0 | = | | / | |\n"
              << "| |___|___|___| |___| |\n"
              << "|_____________________|\n"
              << "\n\n\n\n";

    Lexer lexer;
    bool vocabulary_is_ok( false );
    bool syntax_is_ok( false );
    while( !( vocabulary_is_ok && syntax_is_ok ) )
    {
        lexer.clear();
        std::cout << "\n\n Please enter a valid expression:\n\n> ";
        CustomString user_input;
        std::cin >> user_input;
        lexer.init( user_input );
        vocabulary_is_ok = check_vocabulary( lexer );
        if( vocabulary_is_ok )
        {
            syntax_is_ok = check_syntax( lexer );
        }
    }

    Parser parser( lexer.words_ );

    parser.parse_expression();
    std::cout << "Result: " << parser.evaluate_expression().value() << "\n";
    return 0;
}
