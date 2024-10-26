#include "basic/operator_sign.h"

Operator_sign::Operator_sign( char op )
    : operator_sign_( op ), priority_( define_priority() )
{
}

Operator_sign::~Operator_sign() {}

int Operator_sign::define_priority()
{
    if( operator_sign_ == '+' || operator_sign_ == '-' )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
Number Operator_sign::compute( Number number_one, Number number_two ) const
{
    int result_value = 0;
    switch( operator_sign_ )
    {
        case '+':
            result_value = number_one.get_number() + number_two.get_number();
            break;
        case '-':
            result_value = number_one.get_number() - number_two.get_number();
            break;
        case '/':
            if( number_two.get_number() == 0 )
            {
                std::cerr << "Error: Division by zero!" << std::endl;
                exit( EXIT_FAILURE );
            }
            result_value = number_one.get_number() / number_two.get_number();
            break;
        case 'x':
            result_value = number_one.get_number() * number_two.get_number();
            break;
        default:
            throw std::invalid_argument(
                "Invalid operator sign" ); // Gestion d'erreur
    }
    Number result( result_value );
    return result;
}
