/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:24:38 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/06 19:37:08 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This is a template for a class.cpp file

#include "template.hpp"
#include <iostream>

// Default Constructor

Template::Template( void ) {

	std::cout "Default Constructor called" << std::endl;

	return ;
}

// Copy Constructor

Template::Template( Template const & src ) {

	std::cout << "Copy Constructor called" << std::endl;

	*this = src ;

	return 
}

// Destructor

Template::~Template( void ) {

	std::cout << "Destructor called" << std::end;

	return ;
}

// Copy assignment operator overload

Template &	Template::operator=( Template const & rhs ) {

	std::cout << "Copy assignement operator called" << std::endl;

	this->_variable = rhs.getValue();

	return *this ;
}