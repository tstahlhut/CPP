/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:57:10 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/07 11:42:44 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/*            			Constructors & Destructor                             */
/* ************************************************************************** */

// Default Constructor: initializes fixed-point number value to 0
Fixed::Fixed( void ) : _raw( 0 ) {

	std::cout << "Default Constructor called" << std::endl;

	return ;
}

// Int Constructor: converts i to the corresponding fixed-point value
Fixed::Fixed( const int i ) : _raw(i << _fractionalBits) {

	std::cout << "Int Constructor called" << std::endl;
	
	return ;
}

// Float Constructor: converts float to fixed-point value
Fixed::Fixed( const float f ) {

	std::cout << "Float Constructor called" << std::endl;

		this->_raw = roundf(f * (1 << _fractionalBits));
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

/* ************************************************************************** */
/*            			Static Variables		                              */
/* ************************************************************************** */

const int	Fixed::_fractionalBits = 8;


/* ************************************************************************** */
/*            			Member Functions		                              */
/* ************************************************************************** */

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

// converts fixed-point value to floating-point value
float	Fixed::toFloat( void ) const {

/*	float	floatNum;
	int	i;

	i = this->_fractionalBits;

	while (i--) 
		floatNum = this->_raw << i;*/
	
	return (float)this->_raw / (1 << _fractionalBits);
}	

// converts fixed-point value to integer value
int		Fixed::toInt( void ) const {

/*	int	intNum;
	int	i;

	i = this->_fractionalBits;

	while (i--) 
		intNum = this->_raw >> i;*/

	return this->_raw >> _fractionalBits;
}

// inserts a floating-point representation of the fixed-point number into the output stream object passed as parameter
std::ostream &	operator<<( std::ostream & o, Fixed const & rhs ) {

	o << rhs.toFloat();

	return o;
}