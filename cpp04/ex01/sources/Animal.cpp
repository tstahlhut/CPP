/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:24:38 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/11 16:34:50 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

// Default Constructor

Animal::Animal( void ) {

	std::cout << "Default Animal Constructor called" << std::endl;

	return ;
}

// Copy Constructor

Animal::Animal( Animal const & src ) {

	std::cout << "Copy Animal Constructor called" << std::endl;

	*this = src ;

	return ;
}

// Destructor

Animal::~Animal( void ) {

	std::cout << "Animal Destructor called" << std::endl;

	return ;
}

// Copy assignment operator overload

Animal &	Animal::operator=( Animal const & rhs ) {

	std::cout << "Animal Copy assignement operator called" << std::endl;

	if (this == &rhs)
		return *this;

	this->_type = rhs.getType();

	return *this ;
}

std::string	Animal::getType( void ) const {

	return this->_type;
}

void	Animal::makeSound( void ) const {

	std::cout << "*some animal sound*" << std::endl;
}