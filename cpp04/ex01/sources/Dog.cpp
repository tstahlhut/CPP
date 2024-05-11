/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:24:38 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/11 17:42:03 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Default Constructor

Dog::Dog( void ) {

	std::cout << "Default Dog Constructor called" << std::endl;

	this->_type = "Dog";
	this->_dogBrain = new Brain();
	
	return ;
}

// Copy Constructor

Dog::Dog( Dog const & src ) {

	std::cout << "Copy Dog Constructor called" << std::endl;

	*this = src ;

	return ;
}

// Destructor

Dog::~Dog( void ) {

	delete _dogBrain;
	
	std::cout << "Dog Destructor called" << std::endl;

	return ;
}

// Copy assignment operator overload

Dog &	Dog::operator=( Dog const & rhs ) {

	std::cout << "Dog Copy assignement operator called" << std::endl;

	if (this == &rhs)
		return *this;

	this->_type = rhs.getType();

	return *this ;
}

void	Dog::makeSound( void ) const {

	std::cout << "*bark*" << std::endl;
}