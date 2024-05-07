/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:24:38 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/07 19:05:51 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This is the implementation of the ClapTrap class

#include "ClapTrap.hpp"
#include <iostream>

/* ************************************************************************** */
/*            			Constructors & Destructor                             */
/* ************************************************************************** */


ClapTrap::ClapTrap( void ) {

	std::cout "Default Constructor called" << std::endl;

	return ;
}

ClapTrap::ClapTrap( std::string name ) : _name( name ) {

	std::cout "Constructor called" << std::endl;

	this->_health = 10;
	this->_energy = 10;
	this->_damage = 0;

	return ;
}

ClapTrap::ClapTrap( ClapTrap const & src ) {

	std::cout << "Copy Constructor called" << std::endl;

	*this = src ;

	return 
}

ClapTrap::~ClapTrap( void ) {

	std::cout << "Destructor called" << std::end;

	return ;
}

/* ************************************************************************** */
/*            			Member Functions		                              */
/* ************************************************************************** */


// Copy assignment operator overload

ClapTrap &	ClapTrap::operator=( ClapTrap const & rhs ) {

	std::cout << "Copy assignement operator called" << std::endl;

	this->_variable = rhs.getValue();

	return *this ;
}

// getter function

std::string	ClapTrap::getName( ClapTrap const & src ) {

	return this->_name;
}

void	ClapTrap::attack( const std::string& target ) {

	std::cout << this->_name << " attacks " << target;
	std::cout << ", causing " << this->_damage << " points of damage!" << std::endl;



}
		void	ClapTrap::takeDamage( unsigned int amount );
		void	ClapTrap::beRepaired( unsigned int amount );