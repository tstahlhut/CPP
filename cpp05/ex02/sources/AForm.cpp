/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:02:27 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/17 17:14:57 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

// Default constructor

AForm::AForm( void ) : _name("default"), _signed(false), _gradeSign(150), _gradeExec(1) {

	std::cout << "AForm default constructor called" << std::endl;

	return ;
}

// Constructor

AForm::AForm( std::string AFormName, int const gradeToSignAForm, int const gradeToExecuteAForm ) :
								_name(AFormName), 
								_signed(false),
								_gradeSign(gradeToSignAForm), 
								_gradeExec(gradeToExecuteAForm) {

	std::cout << "AForm constructor called" << std::endl;

	if (gradeToSignAForm < 1 || gradeToExecuteAForm < 1)
		throw GradeTooHighException();
	if (gradeToSignAForm > 150 || gradeToExecuteAForm > 150)
		throw GradeTooLowException();

	return ;
}

AForm::AForm( AForm const & src ) :
	_name(src._name),
	_gradeSign(src._gradeSign),
	_gradeExec(src._gradeExec) {

	std::cout << "AForm copy constructor called" << std::endl;

	*this = src;

	return;
}

AForm&	AForm::operator=( AForm const & rhs ) {

	std::cout << "AForm copy assignement operator called" << std::endl;

	if (this != &rhs) {

		this->_signed = rhs._signed;
		// as the other attributes are constant, they cannot be changed
	}
	return *this;
}

AForm::~AForm( void ) {

	std::cout << "AForm destructor called" << std::endl;

	return ;
}


// Getters

std::string	AForm::getName( void ) const {

	return this->_name;
}

bool		AForm::isSigned( void ) const {

	return this->_signed;
}

int	AForm::getGradeToSign( void ) const {
	
	return this->_gradeSign;
}

int	AForm::getGradeToExec( void ) const {

	return this->_gradeExec;
}


// Other member functions

void		AForm::beSigned( Bureaucrat const & bureaucrat ) {

	if (!this->isSigned()) {

		if (bureaucrat.getGrade() <= this->getGradeToSign())
			this->_signed = true;
		else
			throw GradeTooLowException();
	}
	return ;
}

// operators

std::ostream&	operator<<( std::ostream & o, AForm const & rhs ) {

	o << "AForm: " << rhs.getName() << ". Status: ";
	if (!rhs.isSigned())
		o << "not ";
	o << "signed. Grade required to sign it: " << rhs.getGradeToSign() << ". ";
	o << "Grade required to execute it: " << rhs.getGradeToExec() << ".";

	return o;
}
