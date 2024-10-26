#pragma once
#include <basic/custom_string.h>
#include <iostream>

/**
 * @class Word
 * @brief Class representing a single element of a mathematical expression.
 *
 * @details The class Word correspond to an entity involved in a mathematical
 * calculus this entity can either be a number or an operator.
 */

class Word
{
public:
    Word(); //! @brief Default constructor for the Word class.
    virtual ~Word(); //! @brief Destructor for the Word class.

    /**
     * @brief Returns the category of the word.
     * Pure virtual method that must be overridden by derived classes.
     * @return The category of the word as a CustomString.
     */
    virtual CustomString category() const = 0;

    /**
     * @brief Returns the value of the word.
     * Pure virtual method that must be overridden by derived classes.
     * @return The value of the word as a CustomString.
     */
    virtual CustomString value() const = 0;

    /**
     * @brief Displays the mathematical calculus.
     * @param operation The calculus to display.
     */
    virtual void display_word( CustomString operation );

    /**
     * @brief Appends a digit to the word.
     * @details Function to append a digit to the word in order to create a
     * larger number This method is virtual and can be overridden for specific
     * behavior.
     * @param digit The digit to append, represented as a CustomString.
     */
    virtual void append_digit( CustomString digit );
    /**
     * @brief Defines the priority of the word, as long as the word is an
     * operator.
     * @details This virtual method returns 0 by default. It can be
     * overridden in derived classes to introduce custom priority handling
     * logic.
     * @return Returns 0 by default.
     */
    virtual int define_priority();
};
