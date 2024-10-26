#include <basic/custom_string.h>
#include <basic/lexer.h>
#include <iostream>

Lexer::Lexer() : words_() {}

Lexer::~Lexer()
{
    clear();
}

void Lexer::init( CustomString& user_input )
{
    char first_character = user_input[0];
    WordType word_type( define_type( first_character ) );
    if( word_type == number_type )
    {
        words_.push_back( new Number( first_character ) );
    }
    else if( word_type == operator_type )
    {
        words_.push_back( new Operator_sign( first_character ) );
    }
    else
    {
        words_.push_back( new Invalid( first_character ) );
    }
    for( size_t character_index( 1 ); character_index < user_input.length();
         ++character_index )
    {
        char current_character = user_input[character_index];
        WordType current_type( define_type( current_character ) );
        if( current_type
            == number_type ) // if the current character is a number
        {
            if( words_[words_.size() - 1]->category()
                == "number" ) // and if the last word is a number
            {
                words_[words_.size() - 1]->append_digit(
                    current_character ); // append the current character to the
                                         // last word
            }
            //         else if( words_[words_.size() - 1]->category() ==
            //         "operator"
            //                  && words_[words_.size() - 1]->value()
            //                         == "-" ) // and if the last word is the
            //                         operator -
            //{
            //             words_[words_.size() - 1]->transform_to_plus();
            //	words_.push_back( new Number( current_character, negative=true )
            //);
            //}
            else
            {
                words_.push_back( new Number( current_character ) );
            }
        }
        else if( current_type == operator_type )
        {
            words_.push_back( new Operator_sign( current_character ) );
        }
        else
        {
            words_.push_back( new Invalid( current_character ) );
        }
    }
}

void Lexer::clear()
{
    for( size_t elem_index( 0 ); elem_index < words_.size(); ++elem_index )
    {
        delete words_[elem_index];
    }
    words_.clear();
}

WordType Lexer::define_type( char character ) const
{
    if( character >= '0' && character <= '9' )
    {
        return number_type;
    }
    else if( character == '+' || character == '-' || character == 'x'
             || character == '/' )
    {
        return operator_type;
    }
    return invalid_type;
}

int Lexer::verify_words() const
{
    for( int word_index( 0 ); word_index < words_.size(); ++word_index )
    {
        if( words_[word_index]->category() == "invalid" )
        {
            return word_index;
        }
    }
    return -1;
}

size_t Lexer::verify_syntax() const
{
    if( words_[0]->category() != "number" )
    {
        return 0;
    }
    for( int word_index( 1 ); word_index < words_.size(); ++word_index )
    {
        if( words_[word_index]->category()
            == words_[word_index - 1]->category() )
        {
            return word_index;
        }
    }
    if( words_[words_.size() - 1]->category() != "number" )
    {
        return words_.size();
    }
    return 99999;
}

CustomString Lexer::output() const
{
    CustomString output_string;
    for( size_t word_index( 0 ); word_index < words_.size(); ++word_index )
    {
        output_string.append( words_[word_index]->value() );
        output_string.append( " " );
    }
    return output_string;
}

std::ostream& operator<<( std::ostream& out, const Lexer& lexer )
{
    for( size_t word_index( 0 ); word_index < lexer.words_.size();
         ++word_index )
    {
        out << lexer.words_[word_index]->value() << " ";
    }
    return out;
}