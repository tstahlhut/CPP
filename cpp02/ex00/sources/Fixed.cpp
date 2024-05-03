/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:57:10 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/03 17:36:16 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Default Constructor: initializes fixed-point number value to 0
Fixed::Fixed( void )
{
	std::cout << "Constructor called" << std::endl;
	this->_fixedPointValue = 0;
	return ;
}

//Copy Constructor
Fixed::Fixed( const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointValue = other._fixedPointValue;
	this->_numBits = other._numBits;
	
}
// Copy assignment operator overload


//Destructor
Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int		Fixed::getRawBits( void ) const
{
	//returns the raw value of the fixed-point value
	return this->_fixedPointValue; // not sure if this is correct
}

void	setRawBits( int const raw )
{
	// sets the raw value of the fixed-point number
	return ;
}