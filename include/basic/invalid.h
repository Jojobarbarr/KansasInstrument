#pragma once
#include "basic/word.h"

/**
 * @class Invalid
 * @brief Derived class from Word representing an invalid character.
 *
 * @details This class defines a specific type of Word that holds an invalid
 * character, used for handling unexpected or unrecognized symbols in input.
 */

class Invalid : public Word
{
private:
    /**
     * @brief brief Holds the invalid character that was
     * unrecognized or unexpected.
     */
    char invalid_char_;

public:
    /**
     * @brief Constructor for the Invalid class.
     * @param invalid_char A character representing the unexpected or
     * unrecognized symbol.
     */
    Invalid( char invalid_char_ );

    /**
     * @brief Destructor for the Invalid class.
     */
    ~Invalid();

    /**
     * @brief Returns the category of the word.
     * In this derived class, the category is "invalid", indicating that the
     * word contains an unrecognized or unexpected character.
     * @return A CustomString containing the word "invalid".
     */
    inline CustomString category() const override
    {
        return "invalid";
    }

    /**
     * @brief Retrieves the invalid character as a CustomString.
     * @return A CustomString containing the invalid character.
     */
    inline CustomString value() const override
    {
        return CustomString( invalid_char_ );
    }
};
