#pragma once
#include <basic/custom_string.h>
#include <basic/dyn_array.h>
#include <basic/invalid.h>
#include <basic/number.h>
#include <basic/operator_sign.h>

/**
 * @enum WordType
 * @brief Enumeration for different types of words (tokens) that can be
 * recognized.
 */

enum WordType
{
    number_type, //! @brief Indicates a number.
    operator_type, //! @brief Indicates an operator.
    invalid_type //! @brief Indicates an invalid character.
};

/**
 * @class Lexer
 * @brief Lexical analyzer that converts user input into a series of words.
 * @details The Lexer class analyzes the input string and breaks it down into
 * words, which can be a number, an operator, or an invalid character.
 */
class Lexer
{
public:
    Lexer(); //! @brief Default constructor for the Lexer class.
    ~Lexer(); //! @brief Destructor for the Lexer class.

    /**
     * @brief Initializes the Lexer with a user input string.
     * Processes the input string, breaking it down into words (tokens)
     * and storing them in the DynArray of words.
     * @param user_input The input string to analyze.
     */
    void init( CustomString& user_input );

    void clear(); //! @brief Clears the Lexer data.

    /**
     * @brief Overloaded output stream operator for displaying Lexer content.
     * Outputs the contents of the Lexer (words) to an output stream.
     * @param lexer The Lexer object to display.
     * @return Reference to the output stream.
     */
    friend std::ostream& operator<<( std::ostream&, const Lexer& );

    /**
     * @brief Verifies the validity of the words.
     * Checks the words identified by the Lexer to ensure they are valid,
     * returning a status code indicating whether any errors were found.
     * @return An integer status code (-1 for success, a positive or null value
     * for errors).
     */
    int verify_words() const;

    /**
     * @brief Verifies the syntax of the input.
     * Analyzes the sequence of words to ensure they form a valid syntactical
     * expression.
     * @return A size_t index of the word responsible for the invalid syntax
     * (99999 for no error).
     */
    size_t verify_syntax() const;

    /**
     * @brief Outputs the analyzed input as a formatted string.
     * Provides a CustomString representation of the analyzed input.
     * @return A CustomString containing the formatted output.
     */
    CustomString output() const;

    /**
     * @brief Dynamically resizable array of Word pointers
     * representing the input.
     */
    DynArray< Word* > words_;

private:
    /**
     * @brief Determines the type of a given character.
     * Classifies the input character as a number, operator, or invalid
     * character.
     * @param character The character to classify.
     * @return The WordType corresponding to the character.
     */
    WordType define_type( char character ) const;
};
