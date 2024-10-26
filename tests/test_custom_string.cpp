#include <basic/custom_string.h>
#include <iostream>

int main()
{
    CustomString cs1;
    CustomString cs2( "Hello, World!" );
    std::cout << cs1 << "\n\n";
    std::cout << cs2 << "\n";
    return 0;
}
