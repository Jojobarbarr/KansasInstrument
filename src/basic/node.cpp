#include <basic/node.h>

Node::Node( const Operator_sign* oper, size_t index )
    : son_lhs_( nullptr ),
      son_rhs_( nullptr ),
      oper_( oper ),
      result_( nullptr ),
      parent_index_( 0 ),
      index_( index )
{
}

Node::Node( const Number* number, size_t index )
    : son_lhs_( nullptr ),
      son_rhs_( nullptr ),
      oper_( nullptr ),
      result_( number ),
      parent_index_( 0 ),
      index_( index )
{
}

Node::Node( const Node* rhs, size_t index )
    : son_lhs_( rhs->son_lhs_ ),
      son_rhs_( rhs->son_rhs_ ),
      oper_( rhs->oper_ ),
      result_( rhs->result_ ),
      parent_index_( 0 ),
      index_( index )
{
}

Node::~Node() {}

void Node::set_son_lhs_( Node& son_lhs, size_t parent_index )
{
    if( this == &son_lhs )
    {
        son_lhs_ = nullptr;
    }
    else
    {
        son_lhs_ = &son_lhs;
        son_lhs.set_parent_index_( parent_index );
    }
}

void Node::set_son_rhs_( Node& son_rhs, size_t parent_index )
{
    if( this == &son_rhs )
    {
        son_rhs_ = nullptr;
    }
    else
    {
        son_rhs_ = &son_rhs;
        son_rhs.set_parent_index_( parent_index );
    }
}

void Node::set_result_( const Number& result )
{
    result_ = &result;
}

Number Node::evaluate() const
{
    // If this node contains a number, return it
    if( result_ != nullptr )
    {
        return *result_;
    }

    // If this node contains an operator, evaluate the left and right subtrees
    if( oper_ != nullptr )
    {
        Number lhs_value = son_lhs_->evaluate();
        Number rhs_value = son_rhs_->evaluate();

        // Apply the operator to the values
        return oper_->compute( lhs_value, rhs_value );
    }

    // Error case (shouldn't happen if the tree is valid)
    throw std::runtime_error( "Invalid node: no result or operator." );
}

size_t Node::parent_index() const
{
    return parent_index_;
}

size_t Node::index() const
{
    return index_;
}

void Node::set_parent_index_( size_t parent_index )
{
    parent_index_ = parent_index;
}

void Node::set_index_( size_t index )
{
    index_ = index;
}
