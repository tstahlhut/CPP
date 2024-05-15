/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:24:38 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/14 14:12:31 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Default Constructor

Dog::Dog( void ) {

	std::cout << "Default Dog Constructor called" << std::endl;

	this->_type = "Dog";
	this->_brain = new Brain();
	
	return ;
}

// Copy Constructor: brain has to be set to NULL, otherwise error: uninitialized value

Dog::Dog( Dog const & src ) : _brain(NULL) {

	std::cout << "Copy Dog Constructor called" << std::endl;

	*this = src ;

	return ;
}

// Destructor

Dog::~Dog( void ) {

	delete _brain;
	
	std::cout << "Dog Destructor called" << std::endl;

	return ;
}

// Copy assignment operator overload

Dog &	Dog::operator=( Dog const & rhs ) {

	std::cout << "Dog Copy assignement operator called" << std::endl;

	if (this == &rhs)
		return *this;

	this->_type = rhs.getType();

	if (this->_brain)
		delete _brain;
	this->_brain = new Brain();
	*(this->_brain) = *(rhs.getBrain());

	return *this ;
}

// Getter function

Brain*	Dog::getBrain( void ) const {

	return this->_brain;
}

void	Dog::makeSound( void ) const {

	std::cout << "*bark*" << std::endl;
}