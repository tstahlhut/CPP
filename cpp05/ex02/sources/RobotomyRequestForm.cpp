/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:50:43 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/17 18:06:33 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

// Default constructor

RobotomyRequestForm::RobotomyRequestForm( void ) : 
				AForm("RobotomyRequest", 72, 45) {

	std::cout << "RobotomyRequestForm default constructor called" << std::endl;

	return ;
}

// Constructor

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : 
				AForm("RobotomyRequest", 72, 45),
				_target(target) {

	std::cout << "RobotomyRequestForm constructor called" << std::endl;
	
	return ;
}

// Copy constructor

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) :
				AForm(src) {

	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;

	*this = src;

	return ;
}

// Copy assignment operator

RobotomyRequestForm&	RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs ) {

		if (this != &rhs) {

			//do something? copy target maybe and signed status
		}

		return *this;
}

void	RobotomyRequestForm::execute( Bureaucrat const & executor) const {

	if (!this->isSigned()) {
		std::cout << "Robotomy failed." << std::endl;
		throw NotSignedException();
	}
		
	if (executor.getGrade() > this->getGradeToExec()) {
		std::cout << "Robotomy failed." << std::endl;
		throw GradeTooLowException();
	}

	std::cout << "Rrrrrrrr... Rrrrrrrr... Rrrrrrrr...";
	std::cout << this->_target << " has been robotomized sucessfully 50% of the time." << std::endl;
	
	return ;
}

// Destructor

RobotomyRequestForm::~RobotomyRequestForm( void ) {

	std::cout << "RobotomyRequestForm destructor called" << std::endl;
	
			return ;
}


		