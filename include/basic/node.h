#pragma once
#include <basic/dyn_array.h>
#include <basic/number.h>
#include <basic/operator_sign.h>

/**
 * @class Node
 * @brief Describes and contains nodes of a binary tree.
 * @details A Node instance is stored as a Word instance (either an
 * Operator_sign or a Number instance), liked to a parent node and two child
 * nodes by pointers. As they are part of a larger tree, they are described by
 * their index in a dynamic array of nodes.
 */
class Node
{
public:
    /**
     * @brief Constructor of the class Node from an operator
     * @param oper: Operator_sign instance
     * @param index: index of the Node in the binary tree dynamic array
     */
    Node( const Operator_sign* oper, size_t index );
    /**
     * @brief Constructor of the class Node from a number
     * @param number: Number instance
     * @param index: index of the Node in the binary tree dynamic array
     */
    Node( const Number* number, size_t index );
    /**
     * @brief Constructor of the class Node from another node
     * @param rhs: Node instance
     * @param index: index of the Node in the binary tree dynamic array
     */
    Node( const Node* rhs, size_t index );
    ~Node(); //! @brief Destructor for the Node class.

    void set_son_lhs_(
        Node& son_lhs, size_t parent_index ); //! @brief Mutator for son_lhs_.
    void set_son_rhs_(
        Node& son_rhs, size_t parent_index ); //! @brief Mutator for son_rhs_.
    void set_result_( const Number& result ); //! @brief Mutator for result_.

    size_t parent_index() const; //! @brief Accessor for parent_index.
    size_t index() const; //! @brief Accessor for index.

    void set_parent_index_(
        size_t parent_index ); //! @brief Mutator for parent_index_.
    void set_index_( size_t index ); //! @brief Mutator for index_.

    Number evaluate() const; //! @brief Solves  the node mathematic operation */
    const Operator_sign* oper_; /*!< symbol of the node mathematic operation */

    Node* son_rhs_; /*!< Node instance at the right child branch */

private:
    Node* son_lhs_; /*!< Node instance at the left child branch */

    const Number* result_; /*!< result of the node mathematic operation */

    size_t parent_index_; /*!< index of the parent node in the binary tree
                             dynamic array */
    size_t
        index_; /*!< /*!< index of the node in the binary tree dynamic array */
};