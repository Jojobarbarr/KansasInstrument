#include "basic/word.h"

Word::Word() {}

Word::~Word() {}

void Word::display_word( CustomString operation )
{
    std::cout << "The operation is : " << operation << std::endl;
}
void Word::append_digit( CustomString digit ) {}

int Word::define_priority()
{
    return 0;
}
