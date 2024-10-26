#pragma once
#include <cassert>
#include <iostream>

/**
 * @class DynArray
 * @brief Template class for a dynamic array that resizes automatically.
 *
 * @details This class provides a dynamically resizable array for elements of
 * type T. It supports basic operations such as adding elements, accessing
 * elements, and clearing the array.
 *
 * @tparam T The type of elements stored in the array.
 */

template < class T >
class DynArray
{
public:
    DynArray(); //! @brief Default constructor for DynArray.

    /**
     * @brief Copy constructor for DynArray.
     * Creates a new DynArray as a copy of another DynArray.
     * @param rhs The DynArray to copy from.
     */
    DynArray( const DynArray< T >& rhs );

    /**
     * @brief Clears the dynamic array.
     * The size of the array to zero without modifying its capacity.
     */
    void clear();

    ~DynArray(); //! @brief Destructor for DynArray.

    /**
     * @brief Assignment operator for DynArray.
     * Assigns one DynArray to another, copying the elements.
     * @param rhs The DynArray to assign from.
     * @return Reference to the assigned DynArray.
     */
    DynArray< T >& operator=( const DynArray< T >& rhs );

    /**
     * @brief Adds an element to the end of the array.
     * Resizes the array if necessary before adding the element.
     * @param element The element to add to the array.
     * @return The index of the newly added element.
     */
    size_t push_back( const T element );

    /**
     * @brief Accesses an element at a given index.
     * @param index The index of the element to access.
     * @return Reference to the element at the specified index.
     */
    T& operator[]( size_t index );

    /**
     * @brief Accesses a constant element at a given index.
     * @param index The index of the element to access.
     * @return Constant reference to the element at the specified index.
     */
    const T& operator[]( size_t index ) const;

    /**
     * @brief Returns the number of elements in the array.
     */
    inline size_t size() const
    {
        return size_;
    }

private:
    /**
     * @brief Resizes the array when its capacity is reached.
     * Increases the capacity by the specified augmentation factor.
     * @param augmentation_term The factor by which to increase the capacity
     * (default is 2).
     */
    void resize_array( size_t augmentation_term = 2 );
    size_t size_; //! @brief The number of elements in the array.
    size_t
        capacity_; //! @brief The maximum capacity of the array before resizing.
    T* array_; //! @brief Pointer to the dynamically allocated array.
};

// Implementation of the DynArray methods.

template < class T >
DynArray< T >::DynArray() : size_( 0 ), capacity_( 0 ), array_( nullptr )
{
}

template < class T >
DynArray< T >::~DynArray()
{
    delete[] array_;
}

template < class T >
DynArray< T >::DynArray( const DynArray< T >& rhs )
    : size_( size_ ), capacity_( rhs.capacity_ ), array_( new T[capacity_] )
{
    for( size_t elem_index( 0 ); elem_index < size_; ++elem_index )
    {
        array_[elem_index] = rhs.array_[elem_index];
    }
}

template < class T >
void DynArray< T >::clear()
{
    size_ = 0;
}

template < class T >
DynArray< T >& DynArray< T >::operator=( const DynArray< T >& rhs )
{
    if( this != &rhs )
    {
        delete[] array_;

        size_ = rhs.size_;
        capacity_ = rhs.capacity_;
        array_ = new T[capacity_];
        for( size_t elem_index( 0 ); elem_index < size_; ++elem_index )
        {
            array_[elem_index] = rhs.array_[elem_index];
        }
    }
    return *this;
}

template < class T >
T& DynArray< T >::operator[]( size_t index )
{
    assert( index < size_ );
    return array_[index];
}

template < class T >
const T& DynArray< T >::operator[]( size_t index ) const
{
    assert( index < size_ );
    return array_[index];
}

template < class T >
size_t DynArray< T >::push_back( const T item )
{
    if( size_ == capacity_ )
    {
        resize_array();
    }
    array_[size_] = item;
    return size_++;
}

template < class T >
void DynArray< T >::resize_array( size_t augmentation_term )
{
    capacity_ += augmentation_term;
    T* new_array = new T[capacity_];

    for( size_t elem_index( 0 ); elem_index < size_; ++elem_index )
    {
        if( elem_index == capacity_ )
        {
            break;
        }
        new_array[elem_index] = array_[elem_index];
    }

    delete array_;
    array_ = new_array;
}
