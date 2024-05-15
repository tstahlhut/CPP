/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:24:38 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/15 13:06:37 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

// Default Constructor

AAnimal::AAnimal( void ) {

	std::cout << "Default AAnimal Constructor called" << std::endl;

	return ;
}

// Copy Constructor

AAnimal::AAnimal( AAnimal const & src ) {

	std::cout << "Copy AAnimal Constructor called" << std::endl;

	*this = src ;

	return ;
}

// Destructor

AAnimal::~AAnimal( void ) {

	std::cout << "AAnimal Destructor called" << std::endl;

	return ;
}

// Copy assignment operator overload

AAnimal &	AAnimal::operator=( AAnimal const & rhs ) {

	std::cout << "AAnimal Copy assignement operator called" << std::endl;

	if (this != &rhs) {

		this->_type = rhs.getType();
	}

	return *this ;
}

std::string	AAnimal::getType( void ) const {

	return this->_type;
}
