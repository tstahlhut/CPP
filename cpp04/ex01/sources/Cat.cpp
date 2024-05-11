/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:24:38 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/11 18:12:19 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default Constructor

Cat::Cat( void ) {

	std::cout << "Default Cat Constructor called" << std::endl;

	this->_type = "Cat";
	this->_catBrain = new Brain();
	
	return ;
}

// Copy Constructor

Cat::Cat( Cat const & src ) : Animal(), _catBrain(NULL) {

	std::cout << "Copy Cat Constructor called" << std::endl;

	*this = src ;

	return ;
}

// Destructor

Cat::~Cat( void ) {

	delete _catBrain;
	
	std::cout << "Cat Destructor called" << std::endl;

	return ;
}

// Copy assignment operator overload

Cat &	Cat::operator=( Cat const & rhs ) {

	std::cout << "Cat Copy assignement operator called" << std::endl;

	if (this != &rhs) {
		
		this->_type = rhs.getType();

		if (this->_catBrain) {
			
			delete this->_catBrain;
			this->_catBrain = rhs.getBrain();
		}
	}
	
	return *this ;
}

// Getter function

Brain*	Cat::getBrain( void ) const {

	return this->_catBrain;
}


void	Cat::makeSound( void ) const {

	std::cout << "*meow*" << std::endl;
}