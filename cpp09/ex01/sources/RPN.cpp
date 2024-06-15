/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:24:38 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/15 16:10:18 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/RPN.hpp"

// Default Constructor

RPN::RPN( void ) : _stack() {

	//std::cout << "Default Constructor called" << std::endl;

	return ;
}
/*
RPN::RPN( int n ) : _stack(n) {

	std::cout << "Int Constructor called" << std::endl;

	return ;
}

RPN::RPN( char & c ) : _stack((c - '0')) {

	std::cout << "Char Constructor called" << std::endl;

	return ;
}*/

// Copy Constructor

RPN::RPN( RPN const & src )  {

	//std::cout << "Copy Constructor called" << std::endl;

	*this = src ;

	return ;
}

// Copy assignment operator overload

RPN &	RPN::operator=( RPN const & rhs ) {

//	std::cout << "Copy assignement operator called" << std::endl;

	if (this != &rhs) {

		this->_stack = rhs._stack;

	}

	return *this ;
}

// Destructor

RPN::~RPN( void ) {

//	std::cout << "Destructor called" << std::endl;

	return ;
}

// Iterators
/*
RPN::iterator	RPN::begin() const {

	return this->c.begin();
}

RPN::iterator	RPN::end() const {

	return this->_stack.c.end();
}*/


// Member Functions

std::stack<int>	RPN::getStack( void ) const {

	return this->_stack;
}
/*
void	RPN::calculate( int c ) {

if (this->_stack.empty())
	throw SyntaxErrorException();
int	operand2 = this->_stack.top();
this->_stack.pop();

if (this->_stack.empty())
	throw SyntaxErrorException();
int	operand1 = this->_stack.top();
this->_stack.pop();

this->_stack.push(operand1 )


}*/

int	RPN::getOperand( void ) {

	if (this->_stack.empty())
		throw SyntaxErrorException();

	int	operand = this->_stack.top();

	this->_stack.pop();

	return operand;
}

void	RPN::put( char c) {

	if (isdigit(c)) {
		put(c - '0');
	}
	else {

	int	operand2 = getOperand();
	int	operand1 = getOperand();

	switch (c) {
		case '+':
			this->_stack.push(operand1 + operand2);
			break ;
		case '-':
			this->_stack.push(operand1 - operand2);
			break ;
		case '/':
			this->_stack.push(operand1 / operand2);
			break ;
		case '*':
			this->_stack.push(operand1 * operand2);
			break ;
		default:
			throw WrongSymbolException();
	}
	}
		

	return ;
}

void	RPN::put( int n) {

	this->_stack.push(n);
	
	return ;
}



std::ostream &	operator<<( std::ostream & o, RPN const & rhs ) {

	//o << "Stack: " << std::endl;
	if (rhs.getStack().empty()) {
	//	o << "Stack: empty";
		return o;
	}

//	for (std::stack<int>::container_type::iterator it = rhs.getStack().c.begin(); it != rhs.getStack().c.end(); it++ )
	//	o << *it << std::endl;
	o << rhs.getStack().top() << std::endl;

	return o;
}