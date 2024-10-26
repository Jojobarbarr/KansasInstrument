#pragma once
#include "basic/number.h"

/**
 * @class Operator_sign
 * @brief Derived class from Word representing an operator symbol.
 * @details This class defines a specific type of Word that holds an operator
 * symbol (e.g., '+', '-', 'x', '/') and provides functionality for performing
 * operations on numbers.
 */

class Operator_sign : public Word
{
private:
    /**
     * @brief The operator character
     * (e.g., '+', '-', 'x','/')
     */
    char operator_sign_;
    /**
     * @brief Indicates whether the operator has a high priority
     */
    int priority_;
    int define_priority() override;

public:
    /**
     * @brief Constructor for Operator_sign class.
     * @param op A character representing an operator symbol.
     */
    Operator_sign( char op );

    /**
     * @brief Destructor for Operator_sign class.
     */
    ~Operator_sign();

    /**
     * @brief Returns the category of the word.
     * In this derived class, the category is "operator".
     * @return A CustomString containing the word "operator".
     */
    inline CustomString category() const override
    {
        return "operator";
    }

    /**
     * @brief Returns the value of the operator sign.
     * Retrieves the operator character as a CustomString.
     * @return A CustomString containing the operator symbol.
     */
    inline CustomString value() const override
    {
        return CustomString( operator_sign_ );
    }

    /**
     * @brief Sets the priority of the operator based on the provided character.
     * @param op The operator character to define priority for.
     * @return priority = true if the operator is 'x' or '/'
     *
     * priority = false if the operator is '+' or '-'.
     */
    void define_priority( char op );

    /**
     * @brief Computes the result of applying the operator to two numbers.
     *
     * @details This method performs the mathematical operation represented by
     * the operator on two Number objects (e.g., addition, subtraction,
     * multiplication, division).
     *
     * @param number_one The first operand (Number).
     * @param number_two The second operand (Number).
     * @return The result of the operation as a Number.
     */
    Number compute( Number number_one, Number number_two ) const;

    inline int priority() const
    {
        return priority_;
    }
};
