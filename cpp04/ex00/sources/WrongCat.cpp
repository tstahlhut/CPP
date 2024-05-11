/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:24:38 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/11 16:34:50 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Default Constructor

WrongCat::WrongCat( void ) {

	std::cout << "Default WrongCat Constructor called" << std::endl;

	this->_type = "WrongCat";
	
	return ;
}

// Copy Constructor

WrongCat::WrongCat( WrongCat const & src ) {

	std::cout << "Copy WrongCat Constructor called" << std::endl;

	*this = src ;

	return ;
}

// Destructor

WrongCat::~WrongCat( void ) {

	std::cout << "WrongCat Destructor called" << std::endl;

	return ;
}

// Copy assignment operator overload

WrongCat &	WrongCat::operator=( WrongCat const & rhs ) {

	std::cout << "WrongCat Copy assignement operator called" << std::endl;

	if (this == &rhs)
		return *this;

	this->_type = rhs.getType();

	return *this ;
}

void	WrongCat::makeSound( void ) const {

	std::cout << "*meow*" << std::endl;
}