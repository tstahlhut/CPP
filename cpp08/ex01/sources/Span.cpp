/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:15:13 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/06/13 10:51:36 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

//Default constructor (set private so that class is only instanciable with parameters)
Span::Span( void ) : _array(), _capacity(0) {

	std::cout << "Default Constructor called" << std::endl;

	return ;
}

//Constructor
Span::Span( unsigned int N ) : _capacity(N) {

	std::cout << "Constructor called: maximum capacity: " << N << std::endl;

	return ;
}

//Copy Constructor
Span::Span( Span const & src ) : _array(src._array), _capacity(src._capacity) {

	std::cout << "Copy Constructor called" << std::endl;

	//*this = src ;

	return ;
}

//Destructor
Span::~Span( void ) {

	std::cout << "Destructor called" << std::endl;

	return ;
}


// Copy assignment operator overload
Span &	Span::operator=( Span const & rhs ) {

	std::cout << "Copy assignement operator called" << std::endl;

	if (this != &rhs) {

		//copy capacity
		this->_capacity = rhs._capacity;
		//empty array if not empty
		if (!this->_array.empty())
			this->_array.erase( this->_array.begin(), this->_array.end() );
		//copy array
		if (!rhs._array.empty())
			std::copy( rhs._array.begin(), rhs._array.end(), this->_array.begin() );
		
	}

	return *this ;
}

// Getter Functions

std::deque<int> const &	Span::getArray( void ) const {

	return this->_array;
}


//Member Functions

void	Span::addNumber( int N ) {

	if ( this->_array.size() == this->_capacity )
		throw std::range_error( "Exception: Maximum capacity reached" );
	
	this->_array.push_back(N);
	// or add number with insert:
	//this->_array.insert(this->_array.end(), N);
	return ;
}

void	Span::addRange( std::deque<int>::const_iterator first, std::deque<int>::const_iterator last ) {

	int	numberElements = std::distance( first, last );
	if ( this->_array.size() + numberElements > this->_capacity )
		throw std::range_error( "Exception: Range is too large to fit in");
	this->_array.insert( this->_array.end(), first, last );
	
}

unsigned int	Span::shortestSpan( void ) {

	if (this->_array.size() < 2 )
		throw RangeTooSmall();
	//copy array 
	std::deque<int>	sortedArray(this->_array);
	//sort copied array
	std::sort(sortedArray.begin(), sortedArray.end());
	//look if there is a value twice, if so the span is 0
	if (std::adjacent_find(sortedArray.begin(), sortedArray.end()) != sortedArray.end())
		return 0;

	//calculate span between sorted numbers
	int	span = longestSpan();
	std::deque<int>::iterator it1 = sortedArray.begin();
	std::deque<int>::iterator it2 = sortedArray.begin() + 1;
	while (it2 != sortedArray.end() && span > 1) {
		if (span > (*it2 - *it1))
			span = *it2 - *it1;
		it1++;
		it2++;
	}
	return span;
}


unsigned int	Span::longestSpan( void ) const {

	if (this->_array.size() < 2 )
		throw RangeTooSmall();
	return *(std::max_element( this->_array.begin(), this->_array.end())) - *(std::min_element( this->_array.begin(), this->_array.end()));
}


// Exception

const char *	Span::RangeTooSmall::what( void ) const throw() {

	return "Exception: Range too small to give span";
}



std::ostream &	operator<<( std::ostream & o, Span const & rhs ) {

	std::deque<int>::const_iterator i;

	o << "Span: { ";
	if (rhs.getArray().size() > 0 ) {
		for( i = rhs.getArray().begin(); (i + 1) != rhs.getArray().end(); i++ )
			o << *i << ", ";
		o << *i;
	}
	o << " }";
	return o;
}
