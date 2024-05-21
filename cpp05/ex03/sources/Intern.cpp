/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 08:38:24 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/21 15:50:17 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

// Default Constructor

Intern::Intern( void ) {

	 std::cout << "Intern default constructor called" << std::endl;

	return ;
}

// Copy Constructor

Intern::Intern( Intern const & src ) {

	std::cout << "Intern copy constructor called" << std::endl;

	*this = src ;

	return ;
}

// Copy assignment operator overload

Intern &	Intern::operator=( Intern const & rhs ) {

	std::cout << "Intern copy assignement operator called" << std::endl;

	if (this != &rhs) {

		// nothing to copy
	}

	return *this ;
}

// Destructor

Intern::~Intern( void ) {

	std::cout << "Intern destructor called" << std::endl;

	return ;
}

// Member Function

AForm*	Intern::makeForm( std::string form, std::string target ) {

	AForm*	newForm[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};

	for (int i = 0; i < 3; i++) {
		if (target == newForm[i]->getName()) {
			std::cout << "Intern creates " << newForm[i]->getName() << std::endl;
			return newForm[i];
		}
	}

	std::cout << form << " does not exist. I will make coffee instead." << std::endl;

	return NULL;
}