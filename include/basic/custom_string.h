#pragma once
#include <basic/dyn_array.h>
#include <iostream>

/**
 * @class CustomString
 * @brief A custom string class that provides basic string functionality.
 * @details This class implements a string-like structure using a dynamic array
 * of characters. It supports various operations such as concatenation,
 * indexing, comparison, and conversion between integers and characters.
 */
class CustomString
{
public:
    CustomString(); //! @brief Default constructor for CustomString.

    /**
     * @param user_string A constant character array to initialize the
     * CustomString.
     */
    CustomString( const char user_string[] );

    /**
     * @param character A character to initialize the CustomString.
     */
    CustomString( char character );

    /**
     * @param number An integer to convert to a string.
     */
    CustomString( int number );

    /**
     * @brief Copy constructor for CustomString.
     * Creates a new CustomString as a copy of another CustomString.
     * @param rhs The CustomString to copy from.
     */
    CustomString( const CustomString& rhs );

    ~CustomString(); //! @brief Destructor for CustomString.

    /**
     * @brief Overloaded output stream operator for CustomString.
     * Outputs the contents of the CustomString to an output stream.
     * @param os The output stream to write to.
     * @param cs The CustomString object to output.
     * @return Reference to the output stream.
     */
    friend std::ostream& operator<<( std::ostream& os, const CustomString& cs );

    /**
     * @brief Overloaded input stream operator for CustomString.
     * Inputs a string from an input stream into the CustomString object.
     * @param is The input stream to read from.
     * @param cs The CustomString object to store the input.
     * @return Reference to the input stream.
     */
    friend std::istream& operator>>( std::istream& is, CustomString& cs );

    /**
     * @brief Returns the length of the CustomString.
     */
    inline size_t length() const
    {
        return value_.size() - 1;
    }

    /**
     * @brief Accesses and modifies a character at a given index.
     * @param index The index of the character to access.
     * @return Reference to the character at the specified index.
     */
    char& operator[]( size_t index );

    /**
     * @brief Accesses a constant character at a given index.
     * @param index The index of the character to access.
     * @return The character at the specified index.
     */
    char operator[]( size_t index ) const;

    /**
     * @brief Compares two CustomString objects for equality.
     * @param rhs The CustomString to compare with.
     * @return True if the two strings are equal, otherwise false.
     */
    bool operator==( const CustomString& rhs ) const;

    /**
     * @brief Compares two CustomString objects for inequality.
     * @param rhs The CustomString to compare with.
     * @return True if the two strings are not equal, otherwise false.
     */
    bool operator!=( const CustomString& rhs ) const;

    /**
     * @brief Concatenates two CustomString objects.
     * Returns a new CustomString that is the result of concatenating this
     * string with another.
     * @param rhs The CustomString to concatenate with.
     * @return A new CustomString containing the concatenated result.
     */
    CustomString operator+( const CustomString& rhs ) const;

    /**
     * @brief Appends another CustomString to this one.
     * @param rhs The CustomString to append.
     * @return A reference to this CustomString with the appended value.
     */
    CustomString append( const CustomString& rhs );

    /**
     * @brief Converts the CustomString to an integer.
     * @return The integer value of the string.
     */
    int to_int() const;

private:
    /**
     * @brief Dynamically resizable array of characters
     * representing the string.
     */
    DynArray< char > value_;

    /**
     * @brief Converts a character to its integer equivalent.
     * @param character The character to convert.
     * @return The integer value corresponding to the character.
     */
    int char_to_int( char character ) const;

    /**
     * @brief Converts an integer to its character equivalent.
     * @param number The integer to convert.
     * @return The character representation of the integer.
     */
    char int_to_char( int number ) const;
};
