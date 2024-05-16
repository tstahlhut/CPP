/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:32:36 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/16 11:11:10 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

// Default constructor

Ice::Ice( void ) : AMateria("ice") {

//	std::cout << "Ice default constructor called" << std::endl;

	return ;
}							

// Copy constructor

Ice::Ice( Ice const & src ) {

//	std::cout << "Ice copy constructor called" << std::endl;

	*this = src;
	
	return ;
}

// Assignment operator

Ice &	Ice::operator=( Ice const & rhs ) {

std::cout << "Ice copy assignement operator called" << std::endl;

	if (this != &rhs) {

		// nothing specific to copy
	}
	return *this;
}

// Destructor

Ice::~Ice( void ){

//	std::cout << "Ice destructor called" << std::endl;

	return ;
}

// Member Functions

// clone() will return a new instance of the same type (i.e., if you clone an Ice Materia, you will get a new Ice Materia)
		
AMateria* 	Ice::clone( void ) const {

	AMateria*	newIceMateria = new Ice;

	return newIceMateria;
}


void		Ice::use( ICharacter& target ) {

	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;

	return ;
}
