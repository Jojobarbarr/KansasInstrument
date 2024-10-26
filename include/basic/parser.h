#pragma once
#include <basic/dyn_array.h>
#include <basic/node.h>
#include <basic/number.h>
#include <basic/operator_sign.h>

/**
 * @class Parser
 * @brief Semantic analyzer that converts serie of words instances into a binary
 * semantic tree.
 * @details The Parser class analyzes the input dynamic array of pointer to Word
 * instances and builds a binary semantic tree, which is browsed to evaluate the
 * whole mathematic expression.
 */
class Parser
{
public:
    Parser( const DynArray< Word* >&
            tokens ); //! @brief Constructor for the Parser class.
    ~Parser(); //! @brief Destructor for the Parser class.
    /**
     * @brief Translates the word expression to a semantic binary tree stored in
     * node_. The tree is built applying operations priority rule
     */
    void parse_expression();
    /**
     * @brief Browse the binary tree to evaluate the result of the mathematic
     * expression
     * @return a Numer instance, the result of the expression
     */
    Number evaluate_expression();

private:
    const DynArray< Word* >&
        tokens_; /*!< Contains the mathematic expression to analyse */
    DynArray< Node* > nodes_; /*!< Contains the Node instances forming the
                                 semantic binary tree */

    void minimal_tree(); //! @brief Creates the root of the binary tree.
    size_t root_node_idx_; /*!< index of the Node instance in the binary tree
                              dynamic array */
};