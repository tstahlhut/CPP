/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:02:27 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/17 17:14:57 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

// Default constructor

Form::Form( void ) : _name("default"), _signed(false), _gradeSign(150), _gradeExec(1) {

	std::cout << "Form default constructor called" << std::endl;

	return ;
}

// Constructor

Form::Form( std::string formName, int const gradeToSignForm, int const gradeToExecuteForm ) :
								_name(formName), 
								_signed(false),
								_gradeSign(gradeToSignForm), 
								_gradeExec(gradeToExecuteForm) {

	std::cout << "Form constructor called" << std::endl;

	if (gradeToSignForm < 1 || gradeToExecuteForm < 1)
		throw GradeTooHighException();
	if (gradeToSignForm > 150 || gradeToExecuteForm > 150)
		throw GradeTooLowException();

	return ;
}

Form::Form( Form const & src ) :
	_name(src._name),
	_gradeSign(src._gradeSign),
	_gradeExec(src._gradeExec) {

	std::cout << "Form copy constructor called" << std::endl;

	*this = src;

	return;
}

Form&	Form::operator=( Form const & rhs ) {

	std::cout << "Form copy assignement operator called" << std::endl;

	if (this != &rhs) {

		this->_signed = rhs._signed;
		// as the other attributes are constant, they cannot be changed
	}
	return *this;
}

Form::~Form( void ) {

	std::cout << "Form destructor called" << std::endl;

	return ;
}


// Getters

std::string	Form::getName( void ) const {

	return this->_name;
}

bool		Form::isSigned( void ) const {

	return this->_signed;
}

int	Form::getGradeToSign( void ) const {
	
	return this->_gradeSign;
}

int	Form::getGradeToExec( void ) const {

	return this->_gradeExec;
}


// Other member functions

void		Form::beSigned( Bureaucrat const & bureaucrat ) {

	if (!this->isSigned()) {

		if (bureaucrat.getGrade() <= this->getGradeToSign())
			this->_signed = true;
		else
			throw GradeTooLowException();
	}
	return ;
}

// operators

std::ostream&	operator<<( std::ostream & o, Form const & rhs ) {

	o << "Form: " << rhs.getName() << ". Status: ";
	if (!rhs.isSigned())
		o << "not ";
	o << "signed. Grade required to sign it: " << rhs.getGradeToSign() << ". ";
	o << "Grade required to execute it: " << rhs.getGradeToExec() << ".";

	return o;
}
