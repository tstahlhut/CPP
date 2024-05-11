/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:09:52 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/11 17:40:52 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

// Default Constructor

Brain::Brain( void ) {

	std::cout << "Default Brain Constructor called" << std::endl;

	return ;
}

// Copy Constructor

Brain::Brain( Brain const & src ) {

	std::cout << "Copy Brain Constructor called" << std::endl;

	*this = src ;

	return ;
}

// Destructor

Brain::~Brain( void ) {

	std::cout << "Brain Destructor called" << std::endl;

	return ;
}

// Copy assignment operator overload

Brain &	Brain::operator=( Brain const & rhs ) {

	std::cout << "Brain Copy assignement operator called" << std::endl;

	if (this == &rhs)
		return *this;

	//this->_variable = rhs.getValue();

	return *this ;
}