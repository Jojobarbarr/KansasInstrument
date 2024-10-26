#include "basic/number.h"
#include "basic/operator_sign.h"
#include <cassert>
#include <iostream>

// Test the compute method
void test_compute_method()
{
    Number number_one( '5' ); // Create the first number
    Number number_two( 3 ); // Create the second number

    // Arrays for operators and expected results
    char operators[] = { '+', '-', 'x', '/' };
    int expected_results[] = { 8, 2, 15, 1 };

    // Testing the operators
    for( int i = 0; i < 4; ++i )
    {
        Operator_sign op( operators[i] ); // Create the operator

        Number result = op.compute( number_one, number_two );
        std::cout << "The result for the operation " << operators[i]
                  << " is: " << result.get_number() << std::endl;
        assert(
            result.get_number() == expected_results[i]
            && "The result of the operation is incorrect" ); // Check the result
    }
}

// Main function that executes all tests
int main()
{
    test_compute_method();

    std::cout << "All tests passed for test operator successfully!"
              << std::endl;
    return 0;
}