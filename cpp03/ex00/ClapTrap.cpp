/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:24:38 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/08 11:34:52 by tstahlhu         ###   ########.fr       */
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

	// loses 1 energy point for attacking
	if (this->_health == 0)
		std::cout << this->_name << " is out of health and cannot attack." << std::endl;
	else if (this->_energy == 0)
		std::cout << this->_name << " is out of energy and cannot attack." << std::endl;
	else if (this->_name == target)
		this->_health -= this->_damage;
	else {
		std::cout << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_damage << " points of damage!" << std::endl;
		this->_energy -= 1;
	}
	return ;
}

void	ClapTrap::takeDamage( unsigned int amount ) {

	std::cout << this->_name << " was attacked and lost " << amount << " hit points." << std::endl;
	if (amount > this->_health)
		this->_health = 0;
	else
		this->_health -= amount;
	std::cout << this->_name << ": health(" << this->_health << ")" << std::endl;
	return ;
}


void	ClapTrap::beRepaired( unsigned int amount ) {

i	if (this->_health == 0)
		std::cout << this->_name << " is out of health and cannot repair." << std::endl;
	else if (this->_energy == 0)
		std::cout << this->_name << " is out of energy and cannot repair." << std::endl;
	else {
		this->_energy -= 1;
		this->_health += amount;
		std::cout << this->_name << " repaired itself and got " << amount << " hit points.";
		std::cout << "It now has " << this->_health << " health." << std::endl;
	}
	return ;
}