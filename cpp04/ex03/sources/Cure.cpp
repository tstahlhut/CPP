/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:32:36 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/15 14:57:02 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

// Default constructor

Cure::Cure( void ) : AMateria("cure") {

//	std::cout << "Cure default constructor called" << std::endl;

	return ;
}							

// Copy constructor

Cure::Cure( Cure const & src ) {

//	std::cout << "Cure copy constructor called" << std::endl;

	*this = src;
	
	return ;
}

// Assignment operator

Cure &	Cure::operator=( Cure const & rhs ) {

//	std::cout << "Cure copy assignement operator called" << std::endl;

	if (this != &rhs) {

		// not needed
	}
	return *this;
}

// Destructor

Cure::~Cure( void ){

	//std::cout << "Cure destructor called" << std::endl;

	return ;
}

// Member Functions

// clone() will return a new instance of the same type (i.e., if you clone an Cure Materia, you will get a new Cure Materia)
		
AMateria* 	Cure::clone( void ) const {

	AMateria* newCureMateria = new Cure;

	return newCureMateria;
}


void		Cure::use( ICharacter& target ) {

	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;

	return ;
}
