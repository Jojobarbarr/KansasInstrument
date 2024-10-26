#include "basic/number.h"

Number::Number( char number ) : number_( number - '0' ), negative_( 0 ) {}

Number::Number( int number ) : number_( number ), negative_( 0 ) {}

Number::~Number() {}

void Number::append_digit( CustomString digit )
{
    CustomString unit( number_ );
    unit.append( digit );
    number_ = unit.to_int();
}