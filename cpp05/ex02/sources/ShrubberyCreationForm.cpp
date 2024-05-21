/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:50:43 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/21 15:34:58 by tstahlhu         ###   ########.fr       */
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

ShrubberyCreationForm::ShrubberyCreationForm( std::string const target ) : 
				AForm("ShrubberyCreation", 145, 137),
				_target(target) {

	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
	
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

// Member Functions

void	ShrubberyCreationForm::execute( Bureaucrat const & executor) const {

	if (!isSigned())
		throw NotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	
	// open file with name <target>_shrubbery
	std::string	filename = this->_target;
	filename.append("_shrubbery");
	std::ofstream	outfile(filename.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Failed to open file" << std::endl;
		return ;
	}
	//writes ASCII trees inside it.
	const char* tree =
	 "   /\\\n"
        "  /  \\\n"
        " /    \\\n"
        "/______\\\n"
        "   ||\n"
        "   ||\n"
        "   ||\n";
	for (int i = 0; i < 12; i++)
		outfile << tree << std::endl;
	outfile.close();
	return ;
}


		