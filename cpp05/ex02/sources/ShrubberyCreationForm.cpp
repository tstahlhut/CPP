/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:50:43 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/17 18:06:33 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

// Default constructor

ShrubberyCreationForm::ShrubberyCreationForm( void ) : 
				AForm("ShrubberyCreation", 145, 137) {

	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;

	return ;
}

// Constructor

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : 
				AForm("ShrubberyCreation", 145, 137) {

	std::cout << "ShrubberyCreationForm constructor called" << std::endl;

	//Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.
	// but not on construction but execution, right?
	// save target somewhere?
	
	return ;
}

// Copy constructor

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) :
				AForm(src) {

	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;

	*this = src;

	return ;
}

// Copy assignment operator

ShrubberyCreationForm&	ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs ) {

		if (this != &rhs) {

			//do something? copy target maybe and signed status
		}

		return *this;
}

// Destructor

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {

	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
	
			return ;
}


		