/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 08:38:24 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/21 15:50:17 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

// Default Constructor

Bureaucrat::Bureaucrat( void ) : _name(NULL), _grade(0) {

	 std::cout << "Bureaucrat default constructor called" << std::endl;

	return ;
}

// Constructor

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(grade) {

	std::cout << "Bureaucrat constructor called" << std::endl;

	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();

	return ;
}

// Copy Constructor

Bureaucrat::Bureaucrat( Bureaucrat const & src ) : _name(src._name) {

	std::cout << "Bureaucrat copy constructor called" << std::endl;

	*this = src ;

	return ;
}

// Copy assignment operator overload

Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & rhs ) {

	std::cout << "Bureaucrat copy assignement operator called" << std::endl;

	if (this != &rhs) {

		//this->_name = rhs._name; not updating name because const
		this->_grade = rhs.getGrade();
	}

	return *this ;
}

// Destructor

Bureaucrat::~Bureaucrat( void ) {

	std::cout << "Bureaucrat destructor called" << std::endl;

	return ;
}

// Getters

std::string	Bureaucrat::getName( void ) const {

	return this->_name;
}

int			Bureaucrat::getGrade( void ) const {

	return this->_grade;
}

// Other member functions

void	Bureaucrat::incrementGrade( void ) {

	if (this->_grade > 1)
		this->_grade -= 1;
	else
		throw GradeTooHighException();
	return ;
}

void	Bureaucrat::decrementGrade( void ) {

	if (this->_grade < 150)
		this->_grade += 1;
	else
		throw GradeTooLowException();
	return ;
}

void	Bureaucrat::signForm( AForm & form ) const {

	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed form " << form.getName() << "." << std::endl;
	}
	catch (AForm::GradeTooLowException e)
	{
		std::cout << this->getName() << " could not sign form " << form.getName();
		std::cout << " because form " << form.getName() << " requires level " << form.getGradeToSign();
		std::cout << " and bureaucrat " << this->getName() << " has only level " << this->getGrade() << ".";
		std::cout << std::endl;
	}

	return ;
}

void		Bureaucrat::executeForm( AForm const & form ) {

	try {
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return ;
}

// overload of insertion operator

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs) {

	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return o;
}