/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:35:24 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/06/11 17:27:21 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"


//Template of Default Constructor (creates empty array)
template <typename T>
Array<T>::Array( void ) : _array(NULL), _size(0) {

	std::cout << "Default constructor called" << std::endl;
	
	return;
}

//Template of Constructor (creates array of n elements)
template <typename T>
Array<T>::Array( unsigned int n ) : _array(new T[n]), _size(n) {

	std::cout << "Constructor called: array of size " << n << " created" << std::endl;

	//to prevent a conditional jump because of unitialized values, set all to 0
//	for (unsigned int i = 0; i < this->_size; i++)
//		this->_array[i] = 0;

	return;			
}

//Template of Copy constructor
template <typename T>
Array<T>::Array( Array const & src )  {

	this->_array = NULL;
	this->_size = 0;
	*this = src ;

	std::cout << "Copy Constructor called" << std::endl;

	return ;
}

//Template of Destructor
template <typename T>
Array<T>::~Array( void ) {

	delete [] _array;

	std::cout << "Destructor called" << std::endl;

	return ;
}

//Template of Copy assignment operator
template <typename T>
Array<T> &	Array<T>::operator=( Array const & rhs ) {

	if (this != &rhs) {

		if (this->_array) {
			delete [] this->_array;
			this->_array = NULL;
		}
		if (rhs._array) {
			this->_array = new T[rhs._size];
			for (unsigned int i = 0; i < rhs._size; i++)
				this->_array[i] = rhs._array[i];
			this->_size = rhs._size;
		}
	}

	std::cout << "Copy assignement operator called" << std::endl;

	return *this ;
}

//Template of [] operator overload
template <typename T>
T &	Array<T>::operator[]( unsigned int const n ) const {
	

	if (n >= this->_size){
		throw std::out_of_range("Exception: Element out of bounds");
	}
	return this->_array[n];
}

//Template for Member function
template <typename T>
unsigned int	Array<T>::size( void ) const {

	return this->_size;
}

//Template for operator overload
template< typename T >
std::ostream &	operator<<( std::ostream & o, Array<T> const & a ) {

	o << "array[";
	o << a.size();
	o << "]: {";
	for (unsigned int i = 0; i < (a.size() - 1); i++) {
			o << a[i] << ", ";
	}
	o << a[a.size() - 1] << "}";
	return o;
}

