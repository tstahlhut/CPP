/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:24:38 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/11 16:34:50 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default Constructor

Cat::Cat( void ) {

	std::cout << "Default Cat Constructor called" << std::endl;

	this->_type = "Cat";
	
	return ;
}

// Copy Constructor

Cat::Cat( Cat const & src ) {

	std::cout << "Copy Cat Constructor called" << std::endl;

	*this = src ;

	return ;
}

// Destructor

Cat::~Cat( void ) {

	std::cout << "Cat Destructor called" << std::endl;

	return ;
}

// Copy assignment operator overload

Cat &	Cat::operator=( Cat const & rhs ) {

	std::cout << "Cat Copy assignement operator called" << std::endl;

	if (this == &rhs)
		return *this;

	this->_type = rhs.getType();

	return *this ;
}

void	Cat::makeSound( void ) const {

	std::cout << "*meow*" << std::endl;
}