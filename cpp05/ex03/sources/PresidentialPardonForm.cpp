/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:50:43 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/17 18:06:33 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

// Default constructor

PresidentialPardonForm::PresidentialPardonForm( void ) : 
				AForm("PresidentialPardonForm", 25, 5) {

	std::cout << "PresidentialPardonForm default constructor called" << std::endl;

	return ;
}

// Constructor

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : 
				AForm("PresidentialPardonForm", 25, 5),
				_target(target) {

//	std::cout << "PresidentialPardonForm constructor called" << std::endl;
	
	return ;
}

// Copy constructor

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) :
				AForm(src) {

	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;

	*this = src;

	return ;
}

// Copy assignment operator

PresidentialPardonForm&	PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs ) {

		if (this != &rhs) {

			//do something? copy target maybe and signed status
		}

		return *this;
}

// Destructor

PresidentialPardonForm::~PresidentialPardonForm( void ) {

//	std::cout << "PresidentialPardonForm destructor called" << std::endl;
	
			return ;
}

void	PresidentialPardonForm::execute( Bureaucrat const & executor) const {

	if (!this->isSigned())
		throw NotSignedException();
		
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();

	
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	
	return ;
}