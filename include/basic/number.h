#pragma once
#include "basic/word.h"
#include <basic/custom_string.h>

/**
 * @class Number
 * @brief Derived class from Word representing a numerical word.
 *
 * @details This class defines a specific type of Word that holds a number.
 * It provides functionality for manipulating numbers.
 */

class Number : public Word
{
private:
    int number_; /*!< Holds the numeric value of the word */
    bool negative_;

public:
    /**
     * @brief Constructor for Number class that takes a character.
     * Converts the provided character into an integer and initializes
     * the Number object with that value.
     * @param number A character representing a single digit.
     */
    Number( char number );

    /**
     * @brief Constructor for Number class that takes an integer.
     * Initializes the Number object with the provided integer value.
     * @param number An integer representing the number.
     */
    Number( int number );

    ~Number(); //! @brief Destructor for Number class.

    /**
     * @brief Appends a digit to the number.
     * @details Modifies the numeric value of the Number object by appending
     * a new digit to the current number. The digit is provided as a
     * CustomString.
     * @param digit A CustomString representing a digit to append.
     */
    void append_digit( CustomString digit ) override;

    /**
     * @brief Returns the category of the word.
     * In this derived class, the category is "number".
     * @return A CustomString containing the word "number".
     */
    inline CustomString category() const override
    {
        return "number";
    }

    /**
     * @brief Returns the value of the number.
     * Retrieves the numeric value of the Number as a CustomString.
     * @return A CustomString containing the numeric value.
     */
    inline CustomString value() const override
    {
        return CustomString( number_ );
    }

    /**
     * @brief Retrieves the numeric value as an integer.
     * Returns the underlying integer value stored in the Number.
     * @return The integer value of the Number.
     */
    inline int get_number() const
    {
        return number_;
    }
};
