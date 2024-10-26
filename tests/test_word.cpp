#include "basic/number.h"
#include "basic/operator_sign.h"
#include <cassert>
#include <iostream>

// Test the constructor of the Number class
void test_number_constructor()
{
    Number num( '5' );
    assert( num.value() == "5" ); // Check that the initial value is correct
    assert( num.category() == "number" ); // Check that the category is "number"
}

// Test the constructor of the Operator_sign class
void test_operator_sign_constructor()
{
    Operator_sign op( '+' );
    assert(
        op.value() == "+" ); // Check that the operator is correctly initialized
    assert(
        op.category() == "operator" ); // Check that the category is "operator"
}

// Test appending a digit to Number
void test_number_append_digit()
{
    Number num( '5' );
    num.append_digit( '3' );
    assert(
        num.value() == "53" ); // Check if the value after appending is correct
}

// Test the value of Number
void test_number_value()
{
    Number num( '7' );
    assert( num.value() == "7" ); // Check if the value of the number is correct
}

// Test the category of Number
void test_number_category()
{
    Number num( '1' );
    assert( num.category() == "number" ); // Check if the category is correct
}

// Test the get of Number
void test_get_number()
{
    Number num( '9' );
    assert( num.get_number() == 9 ); // Check if the category is correct
}

// Test the value of Operator_sign
void test_operator_sign_value()
{
    Operator_sign op( '+' );
    assert(
        op.value() == "+" ); // Check if the value of the operator is correct
}

// Test the category of Operator_sign
void test_operator_sign_category()
{
    Operator_sign op( '*' );
    assert( op.category() == "operator" ); // Check if the category is correct
}

// Main function that executes all tests
int main()
{
    // Test the constructors
    test_number_constructor();
    test_operator_sign_constructor();

    // Test other functionalities
    test_number_append_digit();
    test_number_category();
    test_number_value();
    test_get_number();
    test_operator_sign_value();
    test_operator_sign_category();

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
