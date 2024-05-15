/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:24:38 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/15 12:18:28 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default Constructor

Cat::Cat( void ) {

	std::cout << "Default Cat Constructor called" << std::endl;

	this->_type = "Cat";
	this->_brain = new Brain();
	
	return ;
}

// Copy Constructor

Cat::Cat( Cat const & src ) : _brain(NULL) {

	std::cout << "Copy Cat Constructor called" << std::endl;

	*this = src ;

	return ;
}

// Destructor

Cat::~Cat( void ) {

	delete _brain;
	
	std::cout << "Cat Destructor called" << std::endl;

	return ;
}

// Copy assignment operator overload

Cat &	Cat::operator=( Cat const & rhs ) {

	std::cout << "Cat Copy assignement operator called" << std::endl;

	if (this != &rhs) {
		
		this->_type = rhs.getType();

		if (this->_brain)		
			delete this->_brain;
		this->_brain = new Brain();
		*(this->_brain) = *(rhs.getBrain());
	}
	
	return *this ;
}

// Getter function

Brain*	Cat::getBrain( void ) const {

	return this->_brain;
}


void	Cat::makeSound( void ) const {

	std::cout << "*meow*" << std::endl;
}