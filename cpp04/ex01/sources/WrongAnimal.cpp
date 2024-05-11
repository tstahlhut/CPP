/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:24:38 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/11 16:25:26 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

// Default Constructor

WrongAnimal::WrongAnimal( void ) {

	std::cout << "Default WrongAnimal Constructor called" << std::endl;

	return ;
}

// Copy Constructor

WrongAnimal::WrongAnimal( WrongAnimal const & src ) {

	std::cout << "Copy WrongAnimal Constructor called" << std::endl;

	*this = src ;

	return ;
}

// Destructor

WrongAnimal::~WrongAnimal( void ) {

	std::cout << "WrongAnimal Destructor called" << std::endl;

	return ;
}

// Copy assignment operator overload

WrongAnimal &	WrongAnimal::operator=( WrongAnimal const & rhs ) {

	std::cout << "WrongAnimal Copy assignement operator called" << std::endl;

	if (this == &rhs)
		return *this;

	this->_type = rhs.getType();

	return *this ;
}

std::string	WrongAnimal::getType( void ) const {

	return this->_type;
}

void	WrongAnimal::makeSound( void ) const {

	std::cout << "*some WrongAnimal sound*" << std::endl;
}