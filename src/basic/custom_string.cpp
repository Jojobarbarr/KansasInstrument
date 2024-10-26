#include <basic/custom_string.h>

CustomString::CustomString() : value_()
{
    value_.push_back( '\0' );
}

CustomString::CustomString( const char user_string[] ) : value_()
{
    for( size_t index( 0 ); user_string[index] != '\0'; ++index )
    {
        value_.push_back( user_string[index] );
    }
    value_.push_back( '\0' );
}

CustomString::CustomString( char character ) : value_()
{
    value_.push_back( character );
    value_.push_back( '\0' );
}

CustomString::CustomString( int number ) : value_()
{
    int digit( 0 );
    DynArray< char > digits;
    while( number != 0 )
    {
        digit = number % 10;
        digits.push_back( int_to_char( digit ) );
        number /= 10;
    }
    if( digits.size() != 0 )
    {
        for( size_t index( digits.size() - 1 ); index > 0; --index )
        {
            value_.push_back( digits[index] );
        }
        value_.push_back( digits[0] );
    }
    value_.push_back( '\0' );
}

CustomString::CustomString( const CustomString& rhs ) : value_()
{
    for( size_t index( 0 ); index < rhs.length(); ++index )
    {
        value_.push_back( rhs.value_[index] );
    }
    value_.push_back( '\0' );
}
CustomString::~CustomString() {}

std::ostream& operator<<( std::ostream& os, const CustomString& cs )
{
    for( size_t index( 0 ); index < cs.length(); ++index )
    {
        os << cs.value_[index];
    }
    return os;
}

std::istream& operator>>( std::istream& is, CustomString& cs )
{
    char character;
    do
    {
        is.get( character );
    } while( character == '\n' );
    cs.value_[cs.length()] = character; // CustomString has a termination '\0'
                                        // we need to delete before appending.
    while( is.get( character ) && character != '\n' )
    {
        cs.value_.push_back( character );
    }
    cs.value_.push_back( '\0' );
    return is;
}

char& CustomString::operator[]( size_t index )
{
    return value_[index];
}

char CustomString::operator[]( size_t index ) const
{
    return value_[index];
}

bool CustomString::operator==( const CustomString& rhs ) const
{
    if( length() != rhs.length() )
    {
        return false;
    }
    for( size_t index( 0 ); index < length(); ++index )
    {
        if( value_[index] != rhs.value_[index] )
        {
            return false;
        }
    }
    return true;
}

bool CustomString::operator!=( const CustomString& rhs ) const
{
    if( this->operator==( rhs ) )
    {
        return false;
    }
    return true;
}

CustomString CustomString::operator+( const CustomString& rhs ) const
{
    CustomString new_string( *this );
    new_string.append( rhs );
    return new_string;
}

CustomString CustomString::append( const CustomString& rhs )
{
    value_[length()] = rhs.value_[0];
    for( size_t index( 1 ); index < rhs.length(); ++index )
    {
        value_.push_back( rhs.value_[index] );
    }
    value_.push_back( '\0' );
    return *this;
}

int CustomString::to_int() const
{
    int digit( 0 );
    for( size_t index( 0 ); index < length(); ++index )
    {
        digit *= 10;
        digit += char_to_int( value_[index] );
    }
    return digit;
}

int CustomString::char_to_int( char character ) const
{
    char numbers[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    for( int index( 0 ); index < 10; ++index )
    {
        if( character == numbers[index] )
        {
            return index;
        }
    }
    return -1; // should never reach here.
}

char CustomString::int_to_char( int number ) const
{
    char numbers[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    return numbers[number];
}
