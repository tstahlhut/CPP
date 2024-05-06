/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:57:10 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/06 20:44:17 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Default Constructor: initializes fixed-point number value to 0
Fixed::Fixed( void ) : _raw( 0 ) {

	std::cout << "Default Constructor called" << std::endl;

	return ;
}

//Copy Constructor: An instance is created based on passed instance src
Fixed::Fixed( const Fixed& src) {

	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;	
}

//Destructor
Fixed::~Fixed( void ) {

	std::cout << "Destructor called" << std::endl;

	return ;
}

/* Copy assignment operator overload: The current instance (this) is updated
	with the value of the instance rhs. The function returns a reference
	to the current instance, so that operations like a = b = c are possible. */
	
Fixed &	Fixed::operator=( Fixed const & rhs) {

	std::cout << "Copy assignment operator called" << std::endl;
	this->_raw = rhs.getRawBits();

	return *this;
}

// returns the raw value of the fixed-point value
int		Fixed::getRawBits( void ) const {

	std::cout << "getRawBits member function called" << std::endl;
	
	return this->_raw;
}

// sets the raw value of the fixed-point number
void	Fixed::setRawBits( int const raw ) {

	this->_raw = raw;
	
	return ;
}

const int	_numBits = 8;