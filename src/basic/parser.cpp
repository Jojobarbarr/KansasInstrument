#include <basic/parser.h>
#include <iostream>

Parser::Parser( const DynArray< Word* >& tokens )
    : tokens_( tokens ), root_node_idx_( 0 )
{
}

Parser::~Parser()
{
    for( size_t i( 0 ); i < nodes_.size(); ++i )
    {
        delete nodes_[i];
    }
}

void Parser::parse_expression()
{
    if( tokens_.size() == 1 )
    {
        nodes_.push_back(
            new Node( dynamic_cast< Number* >( tokens_[0] ), 0 ) );
        return;
    }
    else // tokens_.size() >= 3 because of the grammar.
    {
        minimal_tree();
        root_node_idx_ = 1;
        for( size_t i( 3 ); i < tokens_.size(); i += 2 )
        {
            size_t comparison_node( root_node_idx_ );
            nodes_.push_back(
                new Node( dynamic_cast< Operator_sign* >( tokens_[i] ), i ) );
            if( nodes_[i]->oper_->priority()
                <= nodes_[root_node_idx_]->oper_->priority() )
            {
                nodes_[i]->set_son_lhs_( *nodes_[root_node_idx_], i );
                nodes_[root_node_idx_]->set_parent_index_( i );
                nodes_.push_back( new Node(
                    dynamic_cast< Number* >( tokens_[i + 1] ), i + 1 ) );
                nodes_[i]->set_son_rhs_( *nodes_[i + 1], i );
                root_node_idx_ = i;
            }
            else
            {
                while( true )
                {
                    comparison_node =
                        nodes_[comparison_node]->son_rhs_->index();
                    if( nodes_[comparison_node]->oper_ == nullptr
                        || nodes_[comparison_node]->oper_->priority()
                               >= nodes_[i]->oper_->priority() )
                    {
                        nodes_[nodes_[comparison_node]->parent_index()]
                            ->set_son_rhs_( *nodes_[i],
                                nodes_[comparison_node]->parent_index() );
                        nodes_[i]->set_son_lhs_( *nodes_[comparison_node], i );
                        nodes_.push_back(
                            new Node( dynamic_cast< Number* >( tokens_[i + 1] ),
                                i + 1 ) );
                        nodes_[i]->set_son_rhs_( *nodes_[i + 1], i );
                        break;
                    }
                }
            }
        }
    }
}

void Parser::minimal_tree()
{
    nodes_.push_back( new Node( dynamic_cast< Number* >( tokens_[0] ), 0 ) );
    nodes_.push_back(
        new Node( dynamic_cast< Operator_sign* >( tokens_[1] ), 1 ) );
    nodes_.push_back( new Node( dynamic_cast< Number* >( tokens_[2] ), 2 ) );
    nodes_[1]->set_son_lhs_( *nodes_[0], 1 );
    nodes_[1]->set_son_rhs_( *nodes_[2], 1 );
}

Number Parser::evaluate_expression()
{
    return nodes_[root_node_idx_]->evaluate();
}
